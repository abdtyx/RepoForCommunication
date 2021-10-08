#include <iostream>
using namespace std;
int main()
{
    int sum, day, hour, minute, second;
    cin >> sum;
    day = sum / 86400;
    hour = (sum - day * 86400) / 3600;
    minute = (sum - day * 86400 - hour * 3600) / 60;
    second = sum - day * 86400 - hour * 3600 - minute * 60;
    cout << sum << " seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, " << second << " seconds";
}