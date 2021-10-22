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



***
#### _log-2021-10-15_:
* 程序主体完成，但是还有一些Bug没修，例如在同一天使用新用户登录时无法获取课表（已修复），并且不知道获取的课表对所有人是否都正确  
* 课表的排序还没做(超级不想做)  
* 获取周和学年学期（已解决）  
#### _log-2021-10-18_: 
* 解决了上述Bug  
* 课表排序依然懒得做  
* 调课信息没有获取  
* gid不能自动获取  
* 更新了gid自动获取功能  
* 优化了输入，现在不需要手动抓memberId了  
* 更改path为绝对路径  
#### _log-2021-10-19_:
* 修复了优化登录次数的bug  
* 正在尝试获取目录自动安装  