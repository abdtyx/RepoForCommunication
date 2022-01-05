#include <bits/stdc++.h>
// #include <sstream>

using namespace std;

typedef pair<string, int> PAIR;

bool mycmp(PAIR a, PAIR b) {
    if (a.second == b.second) return a.first < b.first;
    else 
        return a.second > b.second;
}

int main() {
    vector<PAIR> vec;
    // cin >> tmp;
    // getline(cin, tmp);
    char str[81];
    while (scanf("%s", str) != EOF) {
        // istringstream is(tmp);
        // while (is >> tmp) {
        string tmp(str);
        bool flag = true;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == tmp) {
                vec[i].second++;
                flag = false;
                break;
            }
        }
        if (flag) {
            vec.push_back(make_pair(tmp, 1));
        }
        // cin >> tmp;
        // getline(cin, tmp);
    }
    sort(vec.begin(), vec.end(), mycmp);
    cout << vec[0].first << ' ' << vec[0].second;
    return 0;
}
