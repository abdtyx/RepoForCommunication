#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

typedef pair<int, int> P; // num, ctr

void factor(int n, queue<P>& q) {
    for (int i = 2; i <= n; i++) {
        P p = make_pair(i, 0);
        while (n % i == 0) {
            n /= i;
            p.second++;
        }
        if (p.second != 0) q.push(p);
    }
}

int main() {
    int n, m;
    queue<P> q1, q2;
    cin >> n >> m;
    factor(n, q1);
    factor(m, q2);
    int ans = 1;
    while (q1.size() || q2.size()) {
        if (q1.size() && q2.size()) {
            if (q1.front().first <= q2.front().first) {
                if (q1.front().first == q2.front().first) {
                    if (q1.front().second >= q2.front().second) {
                        ans *= (int)pow(q1.front().first, q1.front().second);
                        q1.pop();
                        q2.pop();
                    }
                    else {
                        ans *= (int)pow(q2.front().first, q2.front().second);
                        q1.pop();
                        q2.pop();
                    }
                }
                else {
                    ans *= (int)pow(q1.front().first, q1.front().second);
                    q1.pop();
                }
            }
            else {
                ans *= (int)pow(q2.front().first, q2.front().second);
                q2.pop();
            }
        }
        else if (q1.size()) {
            ans *= (int)pow(q1.front().first, q1.front().second);
            q1.pop();
        }
        else {
            ans *= (int)pow(q2.front().first, q2.front().second);
            q2.pop();
        }
    }
    cout << ans;
    return 0;
}