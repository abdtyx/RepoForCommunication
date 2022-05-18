#include <iostream>
#include <vector>

using namespace std;

int t[100], a[100];
vector<int> b;

void merge(int ll, int rr) {
  if (rr - ll <= 1) return;
  int mid = ll + ((rr - ll) >> 1);
  merge(ll, mid);
  merge(mid, rr);
  int p = ll, q = mid, s = ll;
  while (s < rr) {
    if (p >= mid || (q < rr && a[p] > a[q])) {
      t[s++] = a[q++];
    } else
      t[s++] = a[p++];
  }
  for (int i = ll; i < rr; ++i) a[i] = t[i];
}

int main() {
    int n;
    cin >> n;
    const int x = 0x2f2f2f2f;
    b.push_back(x);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    merge(0, n);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ' << a[i];
        else cout << a[i];
    }
    cout << endl;

    
    return 0;
}