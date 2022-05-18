#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {return x & (-x);}

#define MAXN 500000

int a[MAXN], c1[MAXN], c2[MAXN];
int n;

void updata(int i, int k) {
    int x = i;
    while (i <= n) {
        c1[i] += k;
        c2[i] += k * (x - 1);
        i += lowbit(i);
    }
}

int getsum(int i) {
    int ans = 0, x = i;
    while (i > 0) {
        ans += x * c1[i] - c2[i];
        i -= lowbit(i);
    }
    return ans;
}

int main() {
    int i, input;
    updata(i, a[i] - a[i - 1]);

    int x, y, k;
    updata(x, k);
    updata(y + 1, -k);

    getsum(y) - getsum(x - 1);
}