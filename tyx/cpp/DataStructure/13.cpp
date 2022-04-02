#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    double polya[1005], polyb[1005];
    memset(polya, 0, sizeof(polya));
    memset(polyb, 0, sizeof(polyb));
    cin >> n;
    for (int i = 0; i < n; i++) {
        int times;
        double value;
        cin >> times >> value;
        polya[times] = value;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int times;
        double value;
        cin >> times >> value;
        polyb[times] = value;
    }
    int ans = 0;
    int where[1005];
    for (int i = 0; i < 1005; i++) {
        polyb[i] += polya[i];
        if (polyb[i] != 0) {
            where[ans++] = i;
        }
    }
    cout << ans;
    for (int i = ans - 1; i >= 0; i--) {
        cout << ' ' << where[i] << ' ' << polyb[where[i]];
    }
    return 0;
}