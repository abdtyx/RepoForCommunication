#include <bits/stdc++.h>
#define MAXN 100
// #define p 998244353

using namespace std;

typedef long long ll;

int n, a[MAXN], ans = 0, t[MAXN];
// 二进制枚举
void binary_enumeration() {
    for (int mask = 0, tot = 1<<n; mask < tot; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask>>i) & 1) sum += a[i];
        }
        if (sum == 0) ans++;
    }
}

// 取模
// a > 0   a % p
// a < 0   a % p + p
// p < 0   a % |p|

// 除法取模

// 指数取模

// 二分查找
bool check(int mid) {
    if (1) return 1;
}
int bsearch_1(int l, int r, int x) {
    // 可取mid
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
int bsearch_2(int l, int r, int x) {
    // 不取mid
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
// upperbound
inline int lower_bound(int a[], int l, int r, int x) {
    // 升序
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
// lowerbound
inline int upper_bound(int a[], int l, int r, int x) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

ll pow_mod(ll a, ll e, ll p) {
    if (e == 0) return 1;
    ll resby2 = pow_mod(a, e / 2, p);
    return resby2 * resby2 % p * ((e & 1) ? a : 1) % p;
}

// merge_sort
void sort(int a[], int l, int r) {
    if (r - l > 1) {
        int mid = (l + r) / 2;
        sort(a, l, mid);
        sort(a, mid, r);
        // merge(a, l, mid, r);
    }
}
void merge(int ll, int rr) {
  // 用来把 a 数组 [ll, rr - 1] 这一区间的数排序。 t
  // 数组是临时存放有序的版本用的。
  if (rr - ll <= 1) return;
  int mid = ll + ((rr - ll) >> 1);
  merge(ll, mid);
  merge(mid, rr);
  int p = ll, q = mid, s = ll;
  while (s < rr) {
    if (p >= mid || (q < rr && a[p] > a[q])) {
      t[s++] = a[q++];
      // ans += mid - p;
    } else
      t[s++] = a[p++];
  }
  for (int i = ll; i < rr; ++i) a[i] = t[i];
}



int main() {
    // merge()
    // a[0] = 7;
    // a[1] = 5;
    // a[2] = 9;
    // a[3] = 10;
    // a[4] = 1;
    // a[5] = 2;
    // a[6] = 8;
    // a[7] = 3;
    // a[8] = 4;
    // a[9] = 6;
    // merge(0, 10);
    // for (int i = 0; i < 10; i++) {cout << a[i] << ' ';}
}