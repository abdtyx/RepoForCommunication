#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t[100], a[100];
vector<int> b;
int n;

int ls(int x) {return x << 1;}
int rs(int x) {return (x << 1) | 1;}

void merge(int ll, int rr) {
    if (rr - ll <= 1) return;
    int mid = ll + ((rr - ll) >> 1);
    merge(ll, mid);
    merge(mid, rr);
    int p = ll, q = mid, s = ll;
    while (s < rr) {
        if (p >= mid || (q < rr && a[p] > a[q])) {
        t[s++] = a[q++];
        }
        else
        t[s++] = a[p++];
    }
    for (int i = ll; i < rr; ++i) a[i] = t[i];
}

void build() {
    int sz = b.size() - 1;
    if (sz & 1) {
        // 有右儿子
        if (b[sz / 2] < b[sz] || b[sz / 2] < b[sz - 1]) {
            if (b[sz] > b[sz - 1]) {
                swap(b[sz], b[sz / 2]);
            }
            else {
                swap(b[sz - 1], b[sz / 2]);
            }
        }
    }
    else {
        if (b[sz / 2] < b[sz]) {
            swap(b[sz / 2], b[sz]);
        }
    }
    for (int i = sz / 2 - 1; i >= 1; i--) {
        if (b[i] < b[ls(i)] || b[i] < b[rs(i)]) {
            if (b[ls(i)] > b[rs(i)]) {
                swap(b[ls(i)], b[i]);
                int cur = ls(i), sz = b.size() - 1;
                while (ls(cur) <= sz && rs(cur) <= sz) {
                    if (b[cur] < b[ls(cur)] || b[cur] < b[rs(cur)]) {
                        if (b[ls(cur)] > b[rs(cur)]) {
                            swap(b[ls(cur)], b[cur]);
                            cur = ls(cur);
                        }
                        else {
                            swap(b[rs(cur)], b[cur]);
                            cur = rs(cur);
                        }
                    }
                    else break;
                }
                if (ls(cur) <= sz) {
                    if (b[cur] < b[ls(cur)]) {
                        swap(b[cur], b[ls(cur)]);
                    }
                }
            }
            else {
                swap(b[rs(i)], b[i]);
                int cur = rs(i), sz = b.size() - 1;
                while (ls(cur) <= sz && rs(cur) <= sz) {
                    if (b[cur] < b[ls(cur)] || b[cur] < b[rs(cur)]) {
                        if (b[ls(cur)] > b[rs(cur)]) {
                            swap(b[ls(cur)], b[cur]);
                            cur = ls(cur);
                        }
                        else {
                            swap(b[rs(cur)], b[cur]);
                            cur = rs(cur);
                        }
                    }
                    else break;
                }
                if (ls(cur) <= sz) {
                    if (b[cur] < b[ls(cur)]) {
                        swap(b[cur], b[ls(cur)]);
                    }
                }
            }
        }
    }
    return;
}

int top() {
    return b[1];
}

void pop() {
    swap(b[1], b[b.size() - 1]);
    b.pop_back();
    int cur = 1, sz = b.size() - 1;
    while (ls(cur) <= sz && rs(cur) <= sz) {
        if (b[cur] < b[ls(cur)] || b[cur] < b[rs(cur)]) {
            if (b[ls(cur)] > b[rs(cur)]) {
                swap(b[ls(cur)], b[cur]);
                cur = ls(cur);
            }
            else {
                swap(b[rs(cur)], b[cur]);
                cur = rs(cur);
            }
        }
        else break;
    }
    if (ls(cur) <= sz) {
        if (b[cur] < b[ls(cur)]) {
            swap(b[cur], b[ls(cur)]);
        }
    }
    return;
}

int main() {
    cin >> n;
    const int x = 0x2f2f2f2f;
    b.push_back(x);
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
        q.push(a[i]);
    }
    merge(0, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ' << a[i];
        else cout << a[i];
    }

    cout << endl;
    build();
    cout << top();
    pop();
    while (b.size() > 1) {
        cout << ' ' << top();
        pop();
    }
    return 0;
}