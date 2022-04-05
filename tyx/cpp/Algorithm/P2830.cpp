#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];
int maxsize[1000];
map<string, int> mp;
int getvalue(string s);

int main() {
    string input1, input2;
    // memset(arr, 0, sizeof(arr));
    // memset(maxsize, 0, sizeof(maxsize));
    int ctr = 0;
    while (cin >> input1) {
        cin >> input2;
        if (input1 == "int") {
            int where = input2.find('[');
            // cout << where;
            string new_array;
            for (int i = 0; i < where; i++) {
                new_array.push_back(input2[i]);
            }
            // cout << new_array << endl;
            int where2 = input2.find_last_of(']');
            string integer;
            for (int i = where + 1; i < where2; i++) {
                integer.push_back(input2[i]);
            }
            maxsize[ctr] = getvalue(integer.c_str());
            if (maxsize[ctr] < 1) {
                cout << -1 << endl;
                return 0;
            }
            mp[new_array] = ctr;
            ctr++;
        }
        else if (input1 == "cout") {
            string s;
            int where1 = input2.find('[');
            int where2 = input2.find_last_of(']');
            for (int i = where1 + 1; i < where2; i++) {
                s.push_back(input2[i]);
            }
            string _array;
            for (int i = 0; i < where1; i++) {
                _array.push_back(input2[i]);
            }
            if (mp.find(_array) == mp.end()) {
                cout << -1 << endl;
                return 0;
            }
            if (maxsize[mp[_array]] <= getvalue(s) || getvalue(s) < 0) {
                cout << -1 << endl;
                return 0;
            }
            else
                cout << arr[mp[_array]][getvalue(s)] << endl;
        }
        else {
            string s;
            int where1 = input1.find('[');
            int where2 = input1.find_last_of(']');
            for (int i = where1 + 1; i < where2; i++) {
                s.push_back(input1[i]);
            }
            string _array;
            for (int i = 0; i < where1; i++) {
                _array.push_back(input1[i]);
            }
            if (mp.find(_array) == mp.end()) {
                cout << -1 << endl;
                return 0;
            }
            if (maxsize[mp[_array]] <= getvalue(s) || getvalue(s) < 0) {
                cout << -1 << endl;
                return 0;
            }
            arr[mp[_array]][getvalue(s)] = getvalue(input2);
        }
    }
    return 0;
}

int getvalue(string s) {
    if (s.find('[') == -1) return atoi(s.c_str());
    string ss;
    int where1 = s.find('[');
    int where2 = s.find_last_of(']');
    for (int i = where1 + 1; i < where2; i++) {
        ss.push_back(s[i]);
    }
    string _array;
    for (int i = 0; i < where1; i++) {
        _array.push_back(s[i]);
    }
    if (mp.find(_array) == mp.end()) {
        cout << -1 << endl;
        exit(0);
    }
    if (maxsize[mp[_array]] <= getvalue(ss) || getvalue(ss) < 0) {
        cout << -1 << endl;
        exit(0);
    }
    return arr[mp[_array]][getvalue(ss)];
}