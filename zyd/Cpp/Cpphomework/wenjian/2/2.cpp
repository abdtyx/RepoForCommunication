#include "ConfigDef.h"
_CONFIG *m_config = NULL;
int main(int argc, char **argv)
{
    m_config = new _CONFIG();
    m_config->InItIniPara("./config.ini");
    cout << "db_address = " << m_config->GetPara("gloabl", "db_address") << endl;
    cout << "db_port = " << m_config->GetPara("gloabl", "db_port") << endl;
    cout << "db_user = " << m_config->GetPara("gloabl", "db_user") << endl;
    cout << "db_name = " << m_config->GetPara("gloabl", "db_name") << endl;
    cout << "db_maxconn = " << m_config->GetPara("gloabl", "db_maxconn") << endl;
    if (m_config != NULL)
    {
        delete m_config;
        m_config = NULL;
    }
    return 0;
}