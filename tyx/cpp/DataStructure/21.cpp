#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    q.pop();
    q.pop();
    q.push(11);
    q.push(12);
    while (q.size()) {
        cout << q.front();
        if (q.front() != 12) {cout << ' ';}
        q.pop();
    }
    return 0;
}