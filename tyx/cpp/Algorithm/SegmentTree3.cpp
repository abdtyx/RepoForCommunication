#include <bits/stdc++.h>

using namespace std;
long long n, sum[400005], ta[400005], tm[400005];
long long p = 571373;

long long ls(long long k) {
    return k << 1;
}

long long rs(long long k) {
    return (k << 1) | 1;
}

/**
 * @brief 
 * 
 * @param k 当前线段树结点编号
 * @param x 左段长度
 * @param y 右段长度
 */
void pushdown(long long k, long long x, long long y) {
    if (ta[k] || tm[k] != 1) {
        sum[ls(k)] = (sum[ls(k)] * tm[k] + ta[k] * x) % p;
        ta[ls(k)] = (ta[ls(k)] * tm[k] + ta[k]) % p;
        tm[ls(k)] = (tm[ls(k)] * tm[k]) % p;
        sum[rs(k)] = (sum[rs(k)] * tm[k] + ta[k] * y) % p;
        ta[rs(k)] = (ta[rs(k)] * tm[k] + ta[k]) % p;
        tm[rs(k)] = (tm[rs(k)] * tm[k]) % p;
        ta[k] = 0;
        tm[k] = 1;
    }
}

void pushup(long long k) {
    sum[k] = (sum[ls(k)] + sum[rs(k)]) % p;
}

// 区间修改
/**
 * @brief 
 * 
 * @param a 区间下界
 * @param b 区间上界
 * @param k 当前线段树结点编号
 * @param l 当前线段树结点左
 * @param r 当前线段树结点右
 * @param x 需要加的数
 */
void add(long long a, long long b, long long k, long long l, long long r, long long x) {
    if (a <= l && r <= b) {
        sum[k] = (sum[k] + (r - l + 1) * x) % p;
        ta[k] = (ta[k] + x) % p;
        return;
    }
    long long m = (l + r) >> 1;
    pushdown(k, m - l + 1, r - m);
    if (a <= m) add(a, b, ls(k), l, m, x);
    if (b > m) add(a, b, rs(k), m + 1, r, x);
    pushup(k);
}

// 区间数乘
/**
 * @brief 
 * 
 * @param a 区间下界
 * @param b 区间上界
 * @param k 当前线段树结点编号
 * @param l 当前线段树结点左
 * @param r 当前线段树结点右
 * @param x 需要乘的数
 */
void mlt(long long a, long long b, long long k, long long l, long long r, long long x) {
    if (a <= l && r <= b) {
        sum[k] = (sum[k] * x) % p;
        tm[k] = (tm[k] * x) % p;
        ta[k] = (ta[k] * x) % p;
        return;
    }
    long long m = (l + r) >> 1;
    pushdown(k, m - l + 1, r - m);
    if (a <= m) mlt(a, b, ls(k), l, m, x);
    if (b > m) mlt(a, b, rs(k), m + 1, r, x);
    pushup(k);
}

// 区间查询
/**
 * @brief 
 * 
 * @param a 查询区间下界
 * @param b 查询区间上界
 * @param k 当前线段树结点编号
 * @param l 当前线段树结点左
 * @param r 当前线段树结点右
 * @return long long 结果
 */
long long ask(long long a, long long b, long long k, long long l, long long r) {
    if (a <= l && r <= b) {
        return sum[k];
    }
    long long m = (l + r) >> 1;
    long long ans = 0;
    pushdown(k, m - l + 1, r - m);
    if (a <= m) ans = (ans + ask(a, b, ls(k), l, m)) % p;
    if (b > m) ans = (ans + ask(a, b, rs(k), m + 1, r)) % p;
    return ans;
}

int main() {
    long long m;
    fill(tm, tm + 400005, 1);
    // memset(tm, 1, sizeof(tm));
    cin >> n >> m >> p;
    for (long long i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        add(i + 1, i + 1, 1, 1, n, tmp);
    }
    for (long long i = 0; i < m; i++) {
        long long s, x, y, k;
        cin >> s;
        if (s == 1) {
            cin >> x >> y >> k;
            mlt(x, y, 1, 1, n, k);
        }
        if (s == 2) {
            cin >> x >> y >> k;
            add(x, y, 1, 1, n, k);
        }
        if (s == 3) {
            cin >> x >> y;
            cout << ask(x, y, 1, 1, n) << endl;
        }
    }
    return 0;
}