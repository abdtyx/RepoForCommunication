#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char chess[200];
    for (int i = 0; i < n; i++) {
        cin >> chess[i];
    }
    char chess2[200];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        memset(chess2, 0, sizeof(chess2));
        strcpy(chess2, chess);
        if (chess2[i] == '.') {
            chess2[i] = 'W';
        }
        else {continue;}
        int res = 0;
        int wflag = -1, bflag = -1, flag = true;
        for (int j = 0; j < n; j++) {
            if (chess2[j] == '.') {wflag = -1; bflag = -1;}
            if (chess2[j] == 'W') {
                if (wflag == -1) {wflag = j;}
                else {res = max(j - wflag - 1, res); wflag = j;}
            }
            if (chess2[j] == 'B') {
                if (bflag == -1) {bflag = j;}
                else {
                    if (j - bflag != 1) {res = 0; flag = false;}
                    bflag = j;
                }
            }
        }
        if (flag)
            ans = max(res, ans);
    }
    cout << ans;
    return 0;
}