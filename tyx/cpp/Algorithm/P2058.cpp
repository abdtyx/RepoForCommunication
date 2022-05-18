#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    queue<pair<int, vector<int> > > ships;
    for (int i = 0; i < n; i++) {
        int time, k;
        cin >> time >> k;
        pair<int, vector<int> > ship;
        ship.first = time;
        for (int j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            ship.second.push_back(tmp);
            if (mp.find(tmp) == mp.end()) mp.insert(make_pair(tmp, 1));
            else mp[tmp]++;
        }
        while (ships.size()) {
            pair<int, vector<int> > f = ships.front();
            if (ship.first - f.first < 86400) break;
            ships.pop();
            for (auto i : f.second) {
                if (mp[i] == 1) mp.erase(i);
                else mp[i]--;
            }
        }
        ships.push(ship);
        cout << mp.size() << endl;
    }
    return 0;
}