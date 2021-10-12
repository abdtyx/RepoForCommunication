import time

localtime = time.localtime(time.time())
print(localtime.tm_wday)
print(localtime.tm_yday, localtime.tm_year, sep=" ")
print(type(localtime.tm_wday))