// 二进制枚举
#include <bits/stdc++.h>

using namespace std;

bool mycmp(queue<int> q1, queue<int> q2);

int main() {
    int n, r;
    cin >> n >> r;
    // 解空间数据结构
    queue<int> q[300];
    int ctr = 0;
    for (int tot = 0, mask = (1 << n); tot < mask; tot++) {
        int tmp = 0;    // 取了几位
        queue<int> temp;
        for (int i = 0; i < n; i++) {
            if (tot & (1 << i)) {
                // 该位取，把n - i放进去
                tmp++;
                temp.push(n - i);
            }
        }
        if (tmp == r) {
            // 是一个解
            q[ctr] = temp;
            ctr++;
        }
    }
    // 排序
    sort(q, q + ctr, mycmp);
    // 输出
    for (int i = 0; i < ctr; i++) {
        while (!q[i].empty()) {
            cout << q[i].front();
            q[i].pop();
        }
        cout << endl;
    }
    return 0;
}

bool mycmp(queue<int> q1, queue<int> q2) {
    int num1 = 0, num2 = 0;
    int sz1 = q1.size(), sz2 = q2.size();
    for (int i = q1.size() - 1; i >= 0; i--) {
        num1 = num1 + q1.front() * (int)pow(10, i);
        q1.pop();
    }
    for (int i = q2.size() - 1; i >= 0; i--) {
        num2 = num2 + q2.front() * (int)pow(10, i);
        q2.pop();
    }
    return num1 > num2;
}