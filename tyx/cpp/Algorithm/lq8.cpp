#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
    queue<int> q1, q2;
    LL s1 = 0, s2 = 0;
    int n;
    LL s;
    cin >> n >> s;
    int* data = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    if (n < 2 || s < 0) {
        cout << "0";
        return 0;
    }

    q1.push(data[0]);
    s1 += data[0];
    q2.push(data[1]);
    s2 += data[1];

    bool flag = false;
    // flag true 表示取2个新data
    // flag false 表示取1个新data并且把q1头部弹出并且把q2头加到q1尾
    int ans = 0;
    if (s1 < s && s2 < s) {
        flag = true;
        ans = 2;
    }
    else {
        flag = false;
    }
    int ctr = 1;
    while (ctr < n) {
        if (flag) {
            // 取2个data加到q2，把q2头放到q1尾
            if (ctr + 2 >= n)
                break;
            else {
                q2.push(data[ctr]);
                s2 += data[ctr++];
                q2.push(data[ctr]);
                s2 += data[ctr++];
                int tmp = q2.front();
                q2.pop();
                s2 -= tmp;
                q1.push(tmp);
                s1 += tmp;
                if (s1 <= s && s2 <= s) {
                    // 一个新的解
                    flag = true;
                    tmp = q1.size() * 2;
                    ans = max(ans, tmp);
                }
                else {
                    // 不是解
                    flag = false;
                }
            }
        }
        else {
            if (ctr + 1 >= n) {
                break;
            }
            else {
                // 取1个data加到q2，把q1头弹出，q2头加到q1尾
                q2.push(data[ctr]);
                s2 += data[ctr++];
                int tmp = q1.front();
                s1 -= tmp;
                q1.pop();
                tmp = q2.front();
                s2 -= tmp;
                q2.pop();
                q1.push(tmp);
                s1 += tmp;
                if (s1 <= s && s2 <= s) {
                    // 一个新的解
                    flag = true;
                    tmp = q1.size() * 2;
                    ans = max(ans, tmp);
                }
                else {
                    // 不是解
                    flag = false;
                }
            }
        }
    }
    cout << ans;
    delete [] data;
    return 0;
}