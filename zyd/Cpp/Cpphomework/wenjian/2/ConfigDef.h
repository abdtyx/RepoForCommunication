#ifndef_CONFIGDEF_H_ 
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