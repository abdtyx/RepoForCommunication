# main  
## import Login, Get_Table  
## userinfo  
## Time detected(decide whether to ask a new table)  
### If true, DayTableInfoList = ReturnDayTableInfo(), then saved. Else, call the existed data.  
## GetChangeInfo()  
## If there is a change, cover the original table with change  
## Output DayTableInfo
***
# Login  
***
# GetTable(Get week table, `once a week`)  
***
# GetChagneInfo(once a day, decide whether to ask a new table)  
***
# HandleWeekTableINfo(ask GetTable())  
## Re(Raw_Code -> WeekTableInfoList)  
## Break WeekTableInfoList to DayTableInfoList  
## Return DayTableInfoList  
***
# ReturnDayTableInfo  
## Return handled data  