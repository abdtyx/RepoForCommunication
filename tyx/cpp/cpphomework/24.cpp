#include <bits/stdc++.h>

using namespace std;


typedef struct _Student {
    string username;
    double total;
    double avg;
} Student;

void Handle_i();


bool mycmp(Student a, Student b) {
    return a.total < b.total;
}



int main() {
    string out[4] = {"1.Input", "2.Output", "3.Order", "4.Quit"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 30; j++) {
            cout << " ";
        }
        cout << out[i] << endl;
    }
    char ch;
    cin >> ch;
    switch (ch)
    {
    case 'm'/* constant-expression */:
        /* code */
        cout << "You are trying to Make things ordered";
        break;
    case 'q':
        cout << "You are about to Quit";
        break;
    case 'i':
        Handle_i();
        break;
    default:
        cout << "Wrong input";
        break;
    }
}





void Handle_i() {
    cout << "Please input info of the three students:" << endl;
    double sc1, sc2, sc3;
    Student stu[3];
    for (int i = 0; i < 3; i++) {
        cin >> stu[i].username >> sc1 >> sc2 >> sc3;
        stu[i].total = sc1 + sc2 + sc3;
        stu[i].avg = stu[i].total / 3.0;
    }
    sort(stu, stu + 3, mycmp);
    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(1) << stu[i].username << "," << stu[i].total << "," << stu[i].avg << endl;
    }
}