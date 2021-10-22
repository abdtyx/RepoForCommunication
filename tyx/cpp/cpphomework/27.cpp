#include <bits/stdc++.h>

using namespace std;

typedef struct _Student {
    string username;
    int cls;
    string name;
    double sc1, sc2, sc3;
} Student;


int main() {
    Student stu[3] = {{"10001", 11, "Zhang", 99.5, 88.5, 89.5}, {"10003", 11, "Liang", 92.5, 99.0, 60.5}, {"10002", 12, "Yang", 77.9, 56.5, 87.5}};
    bool flag = false;
    string cmp;
    cin >> cmp;
    for (int i = 0; i < 3; i++) {
        if (cmp == stu[i].name || cmp == stu[i].username)
            flag = true;
        else
            cout << fixed << setprecision(1) << stu[i].username << " " << stu[i].cls << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3 << endl;
    }
    if (flag) {
        cout << "Are you sure(yes/no)?" << endl;
        char ch;
        cin >> ch;
        if (ch == 'n') {
            for (int i = 0; i < 3; i++) {
                cout << fixed << setprecision(1) << stu[i].username << " " << stu[i].cls << " " << stu[i].name << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3 << endl;
            }
        }
    }
}