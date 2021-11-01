#include <bits/stdc++.h>

using namespace std;

int main() {
    map<int, string> mp;
    mp.clear();
    mp.insert(make_pair(1, "January"));
    mp.insert(make_pair(2, "February"));
    mp.insert(make_pair(3, "March"));
    mp.insert(make_pair(4, "April"));
    mp.insert(make_pair(5, "May"));
    mp.insert(make_pair(6, "June"));
    mp.insert(make_pair(7, "July"));
    mp.insert(make_pair(8, "August"));
    mp.insert(make_pair(9, "September"));
    mp.insert(make_pair(10, "October"));
    mp.insert(make_pair(11, "November"));
    mp.insert(make_pair(12, "December"));
    int ans;
    cin >> ans;
    cout << mp[ans];
    return 0;
}