#include <bits/stdc++.h>
// #include <regex>


using namespace std;

int main() {
    int n;
    pair<string, bool> teachers[3];
    pair<string, bool> students[5];
    cin >> n;
    bool flag[5] = {false, false, false, false, false}; //false表示学生没有被发现，true表示被发现
    for (int i = 0; i < 3; i++) {
        cin >> teachers[i].first;
        teachers[i].second = false;
    }
    for (int i = 0; i < 5; i++) {
        cin >> students[i].first;
        students[i].second = false;
    }
    string teachers_action[2] = {" came!", " left!"};
    string students_action[2] = {" started playing games!", " stopped playing games!"};
    // 吞字符问题
    char abandon;
    cin >> abandon;
    for (int i = 0; i < n; i++) {
        string tmp;
        // cin >> tmp;
        getline(cin, tmp);
        // char str[200];
        // scanf("%[^\n]%*c", str);
        // string tmp(str);
        bool teacher_flag = false;
        //处理老师在线情况
        for (int j = 0; j < 3; j++) {
            //在线
            // regex r(teachers[j].first + teachers_action[0]);
            string r = teachers[j].first + teachers_action[0];
            if (/*regex_match(tmp, r)*/ r == tmp)
                teachers[j].second = true;
            //离线
            // regex r2(teachers[j].first + teachers_action[1]);
            string r2 = teachers[j].first + teachers_action[1];
            if (/*regex_match(tmp, r2)*/ r2 == tmp)
                teachers[j].second = false;
            //老师抓人
            // if (teachers[j].second)
                // teacher_flag = true;
        }
        //老师抓人
        for (int j = 0; j < 3; j++) {
            if (teachers[j].second)
                teacher_flag = true;
        }
        //处理学生在线情况
        for (int j = 0; j < 5; j++) {
            //在线
            // regex r(students[j].first + students_action[0]);
            string r = students[j].first + students_action[0];
            if (/*regex_match(tmp, r)*/ r == tmp)
                students[j].second = true;
            //离线
            // regex r2(students[j].first + students_action[1]);
            string r2 = students[j].first + students_action[1];
            if (/*regex_match(tmp, r2)*/ r2 == tmp)
                students[j].second = false;
            //寄了
            // if (students[j].second && teacher_flag)
                // flag[j] = true;
        }
        // 寄了
        for (int j = 0; j < 5; j++) {
            if (students[j].second && teacher_flag)
                flag[j] = true;
        }
    }
    //输出没被发现的学生
    int ctr = 0;
    for (int i = 0; i < 5; i++) {
        if (flag[i] && ctr == 0) {
            cout << students[i].first;
            ctr++;
        }
        else if (flag[i] && ctr != 0) {
            cout << " " << students[i].first;
            ctr++;
        }
    }
    if (ctr != 0) cout << endl;
    if (ctr == 5)
        cout << "How Bad Oiers Are!";
    if (ctr == 0)
        cout << "How Good Oiers Are!";
    return 0;
}