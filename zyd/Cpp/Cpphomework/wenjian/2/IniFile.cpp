#include "IniFile.h"

CIniParser::CIniParser()
{
    memset(IniFileName, 0, sizeof(IniFileName));
}

CIniParser::~CIniParser()
{
}

bool CIniParser::InItIniPara(string inifile)
{
    memcpy(IniFileName, inifile.c_str(), inifile.length() + 1);
    ReadIniFile();
    ConStructIniMap();
    return true;
}

bool CIniParser::ReadIniFile()
{
    string str_line = "";
    string str_root = "";

    ifstream in_conf_file(IniFileName);
    if (!in_conf_file)
        return false;

    while (getline(in_conf_file, str_line))
    {
        string::size_type left_pos = 0;
        string::size_type right_pos = 0;
        string::size_type equal_div_pos = 0;
        string str_key = "";
        string str_value = "";
        string::size_type note_pos = 0;
        note_pos = str_line.find("#");
        string str_note = "";
        if (note_pos != str_line.npos)
        {
            string str_temp = str_line;
            str_line = str_line.substr(0, note_pos);
            str_note = str_temp.substr(note_pos, str_temp.size() - 1);
            if (str_note.size() > 0)
            {
                cout << "%s is note" << str_note << endl;
            }
        }

        if ((str_line.npos != (left_pos = str_line.find("["))) && (str_line.npos != (right_pos = str_line.find("]"))))
            str_root = str_line.substr(left_pos + 1, right_pos - 1);
        if (str_line.npos != (equal_div_pos = str_line.find("=")))
        {
            str_key = str_line.substr(0, equal_div_pos);
            str_value = str_line.substr(equal_div_pos + 1, str_line.size() - 1);
            str_key = TrimString(str_key);
            str_value = TrimString(str_value);
            //    cout << "<====== " << str_key << " = " << str_value << endl;
        }
        if ((!str_root.empty()) && (!str_key.empty()) && (!str_value.empty()))
        {
            IniNode m_IniNode(str_root, str_key, str_value);
            m_VecIni.push_back(m_IniNode);
        }
    }
    in_conf_file.close();
    in_conf_file.clear();

    return true;
}
bool CIniParser::ConStructIniMap()
{
    MapSubNodeT map_tmp, map_distinc_node;

    for (vector<IniNode>::iterator itr = m_VecIni.begin(); itr != m_VecIni.end(); ++itr)
    {
        map_distinc_node.insert(pair<string, string>(itr->Sroot, ""));
    }

    for (map<string, string>::iterator it = map_distinc_node.begin(); it != map_distinc_node.end(); ++it)
    {
        for (vector<IniNode>::iterator sub_it = m_VecIni.begin(); sub_it != m_VecIni.end(); ++sub_it)
        {
            if (sub_it->Sroot == it->first)
                map_tmp.insert(pair<string, string>(sub_it->Skey, sub_it->Svalue));
        }
        m_MapIni.insert(pair<string, MapSubNodeT>(it->first, map_tmp));
        map_tmp.clear();
    }
    return true;
}

string CIniParser::GetPara(string root, string key)
{
    map<string, MapSubNodeT>::iterator it = m_MapIni.find(root);
    if (it != m_MapIni.end())
    {
        MapSubNodeT::iterator sub_it = it->second.find(key);
        if (sub_it != it->second.end())
            return sub_it->second;
    }
    return "";
}

bool CIniParser::WriteIniFile(string path)
{
    ofstream out_conf_file(path.c_str());
    if (!out_conf_file)
        return false;
    //重写或者备份INI,保证 global 段内容在文件首部。

    map<string, MapSubNodeT>::iterator it_global = m_MapIni.find("global");
    if (m_MapIni.end() != it_global)
    {
        out_conf_file << "\n[" << it_global->first << "]\n"
                      << endl;
        for (MapSubNodeT::iterator subit = it_global->second.begin(); subit != it_global->second.end(); ++subit)
        {
            out_conf_file << "  " << subit->first << " = " << subit->second << endl;
        }
    }

    //其他配置信息写文件
    for (map<string, MapSubNodeT>::iterator it = m_MapIni.begin(); it != m_MapIni.end(); ++it)
    {
        if (it->first == "global")
            continue;
        out_conf_file << "\n[" << it->first << "]\n"
                      << endl;
        for (MapSubNodeT::iterator sub_it = it->second.begin(); sub_it != it->second.end(); ++sub_it)
        {
            out_conf_file << "  " << sub_it->first << " = " << sub_it->second << endl;
        }
    }
    out_conf_file.close();
    out_conf_file.clear();

    return true;
}

void CIniParser::AddPara(string root, string key, string value)
{
    try
    {
        map<string, MapSubNodeT>::iterator it = m_MapIni.find(root);
        if (m_MapIni.end() != it)
        {
            cout << "find root = " << root << "  find key = " << key << "  find value = " << value << endl;
            it->second.insert(pair<string, string>(key, value));
        }
        else
        {
            MapSubNodeT map_tmp;
            map_tmp.insert(pair<string, string>(key, value));
            m_MapIni.insert(pair<string, MapSubNodeT>(root, map_tmp));
        }
    }
    catch (exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
        //exit(-1);
    }
    return;
}

string &CIniParser::TrimString(string &str)
{
    string::size_type pos = 0;

    pos = str.find(" ");
    while (str.npos != pos)
    {
        str.erase(pos, 1);
        pos = str.find(" ");
    }
    return str;
}
