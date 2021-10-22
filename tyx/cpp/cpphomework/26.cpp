#include <bits/stdc++.h>

using namespace std;

typedef struct _Student {
    string username;
    int cls;
    double sc1, sc2, sc3, total;
} Student;


int main() {
    Student stu[4];
    stu[0] = {"10001", 11, 99.5, 88.5, 89.5, 99.5 + 88.5 + 89.5};
    stu[1] = {"10003", 11, 92.5, 99.0, 60.5, 92.5 + 99.0 + 60.5};
    stu[2] = {"10002", 12, 77.9, 56.5, 87.5, 77.9 + 56.5 + 87.5};
    // string tmp;
    cin >> stu[3].username >> stu[3].cls >> stu[3].sc1 >> stu[3].sc2 >> stu[3].sc3;
    stu[3].total = stu[3].sc1 + stu[3].sc2 + stu[3].sc3;
    int flag = -1;
    if (stu[3].username == "10001" || stu[3].username == "10002" || stu[3].username == "10003")
        stu[3].username = "10000";
    if (stu[3].cls == 11) {
        if (stu[3].total >= stu[0].total && stu[3].total <= stu[1].total)
            flag = 0;
        else if (stu[3].total >= stu[1].total)
            flag = 1;
    }
    if (stu[3].cls == 12) {
        if (stu[3].total <= stu[2].total)
            flag = 1;
        if (stu[3].total >= stu[2].total)
            flag = 2;
    }
    if (stu[3].cls > 12)
        flag = 3;
    if (flag == -1)
        cout << fixed << setprecision(1) << stu[3].username << " " << stu[3].cls << " " << stu[3].sc1 << " " << stu[3].sc2 << " " << stu[3].sc3 << " inserted" << endl;
    for (int i = 0; i < 3; i++) {
        if (i == flag)
            cout << fixed << setprecision(1) << stu[3].username << " " << stu[3].cls << " " << stu[3].sc1 << " " << stu[3].sc2 << " " << stu[3].sc3 << " inserted" << endl;
        cout << fixed << setprecision(1) << stu[i].username << " " << stu[i].cls << " " << stu[i].sc1 << " " << stu[i].sc2 << " " << stu[i].sc3 << endl;
    }
    if (flag == 3)
        cout << fixed << setprecision(1) << stu[3].username << " " << stu[3].cls << " " << stu[3].sc1 << " " << stu[3].sc2 << " " << stu[3].sc3 << " inserted" << endl;
}