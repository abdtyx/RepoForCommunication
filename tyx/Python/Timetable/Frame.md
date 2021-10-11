# main  
## import Login, GetTable  
## userinfo  
## Time detected(decide whether to ask a new table)  
### If true, DayTableInfoList = ReturnDayTableInfo(), then saved. Else, call the existed data.  
## GetChangeInfo()  
## If there is a change, cover the original table with change  
## Output DayTableInfo
***
# Login  
## Get userinfo from main and login to ehall
***
# GetTable(Get week table, `once a week`)  
## fetch cookies from block "Login", then ask tableurl with this cookies and other params
***
# GetChagneInfo(once a day, decide whether to ask a new table)  
## fetch cookies from block "Login", then ask changeurl with this cookies and other params
***
# HandleWeekTableInfo(ask GetTable())  
## Re(Raw_Code -> WeekTableInfoList)  
## Break WeekTableInfoList to DayTableInfoList  
## Return DayTableInfoList  
***
# DayTableInfoAPI  
## Return handled data  