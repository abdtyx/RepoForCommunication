#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
    LL sum, days, hours, minutes, seconds;
    cin >> sum;
    LL ans = sum;
    days = sum / 86400;
    sum %= 86400;
    hours = sum / 3600;
    sum %= 3600;
    minutes = sum / 60;
    sum %= 60;
    seconds = sum;
    cout << ans << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
}