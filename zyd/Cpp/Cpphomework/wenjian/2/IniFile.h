#ifndef _CONFIGDEF_H_
#define _CONFIGDEF_H_

#include "IniFile.h"

class _CONFIG : public CIniParser
{
public:
    string db_address;
    short db_port;
    string db_user;
    string db_name;
    int db_maxconn;
};

#endif
#ifndef INI_FILE_H
#define INI_FILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <string.h>

using namespace std;

class IniNode
{
public:
    IniNode(string sInRoot, string sInKey, string sInValue)
    {
        Sroot = sInRoot;
        Skey = sInKey;
        Svalue = sInValue;
    }
    string Sroot;
    string Skey;
    string Svalue;
};

typedef map<string, string> MapSubNodeT;

class CIniParser
{
public:
    CIniParser();
    ~CIniParser();

public:
    bool InItIniPara(string inifile);
    void AddPara(string root, string key, string value);
    bool WriteIniFile(string path);
    string GetPara(string root, string key);
    int GetSize() { return m_MapIni.size(); }
    void Clear() { m_MapIni.clear(); }

private:
    bool ReadIniFile();
    bool ConStructIniMap();
    string &TrimString(string &str);

private:
    char IniFileName[256];

    vector<IniNode> m_VecIni;
    map<string, MapSubNodeT> m_MapIni;
};

#endif
