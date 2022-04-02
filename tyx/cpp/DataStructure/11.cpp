#include <iostream>

using namespace std;

int main() {
    int to;
    int where = 0;
    int ans = 0;
    while (cin >> to) {
        if (to == 0) break;
        int minus = to - where;
        where = to;
        if (minus < 0) ans += -minus * 4;
        else ans += minus * 6;
        ans += 5;
    }
    cout << ans;
    return 0;
}