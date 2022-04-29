#include <bits/stdc++.h>

using namespace std;
#define MAXN 500000
int a[MAXN], c[MAXN];
int n;

int lowbit(int x) {return x & (-x);}

void updata(int i, int k) {
    while (i <= n) {
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i) {
    int res = 0;
    while (i > 0) {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main() {
    // 单改区查
    int input;
    int i;
    a[i] = input;
    updata(i, input);

    int l, r;
    int ans = getsum(r) - getsum(l - 1);
    // 区改单查
    updata(i, a[i] - a[i - 1]);

    updata(l, input);
    updata(r + 1, -input);

    getsum(i);
    // 区改区查
    
}