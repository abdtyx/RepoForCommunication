#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n1 = (s.size() + 2) / 3;
    int space_num = n1 - (n1 * 3 - s.size());
    int front = 0, rear = s.size() - 1;
    for (int i = 0; i < n1; i++) {
        cout << s[front++];
        if (i == n1 - 1) {
            for (int j = front; j <= rear; j++) {
                cout << s[j];
            }
        }
        else {
            for (int j = 0; j < space_num; j++) {
                cout << ' ';
            }
            cout << s[rear--];
        }
        cout << endl;
    }
    return 0;
}