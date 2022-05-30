#include <bits/stdc++.h>

#ifndef _STUDENT_HPP
#include "Student.hpp"
#endif

#ifndef _COURSE_HPP
#include "Course.hpp"
#endif

#ifndef _TREAP_HPP
#include "treap.hpp"
#endif

using namespace std;

vector<Course> courses;
map<int, Student> stunomap;
map<string, vector<Student> > stunamemap;

void menu();

int main() {
    system("chcp 65001");
    system("cls");
    cout << "学籍管理系统" << endl;
    cout << "============" << endl;
    Course ct("平均分");
    courses.push_back(ct);
    int m;
    cout << "请输入课程数量" << endl;
    cin >> m;
    while (m < 1) {
        cout << "课程数量太少！请重新输入：";
        cin >> m;
    }
    for (int i = 0; i < m; i++) {
        cout << "请输入课程名：";
        string name;
        cin >> name;
        Course ctmp(name);
        courses.push_back(ctmp);
    }
    int n;
    cout << "请输入学生数量" << endl;
    cin >> n;
    while (n < 1) {
        cout << "学生数量太少！请重新输入：";
        cin >> n;
    }
    for (int i = 0; i < n; i++) {
        cout << "请输入学生信息（学号、姓名、各科成绩）：";
        int s;
        string n;
        cin >> s >> n;
        Student stmp(s, n);
        for (int j = 1; j <= m; j++) {
            double dtmp;
            cin >> dtmp;
            stmp.append(make_pair(courses[j].coursename(), dtmp));
            courses[j].insertStudent(stmp);
        }
        courses[0].insertavg(stmp, stmp.avg());
        stunomap.insert(make_pair(s, stmp));
        if (stunamemap.find(n) == stunamemap.end()) {
            vector<Student> vtmp;
            vtmp.push_back(stmp);
            stunamemap[n] = vtmp;
        }
        else {
            stunamemap[n].push_back(stmp);
        }
    }
    while (1) {
        menu();
        int c;
        cin >> c;
        switch (c)
        {
        case 1:
            while (1) {
                cout << "请输入课程名：";
                string coursename;
                cin >> coursename;
                if (coursename == "exit") break;
                bool nameflag = true;
                for (auto i : courses) {
                    if (i.name == coursename) {
                        nameflag = false;
                        i.printall();
                        break;
                    }
                }
                if (nameflag) cout << "找不到此课程，请重新输入（放弃输入请输入exit）：";
                else break;
            }
            break;
        case 2:
            courses[0].printall();
            break;
        case 3:
            while (1) {
                cout << "请输入课程名：";
                string coursename;
                cin >> coursename;
                if (coursename == "exit") break;
                bool nameflag = true;
                for (auto i : courses) {
                    if (i.name == coursename) {
                        nameflag = false;
                        i.printdata();
                        break;
                    }
                }
                if (nameflag) cout << "找不到此课程，请重新输入（放弃输入请输入exit）：";
                else break;
            }
            break;
        case 4:
            while (1) {
                cout << "希望通过姓名还是学号查询？输入《姓名》or《学号》" << endl;
                string c2;
                cin >> c2;
                bool flagout = false;
                while (c2 != "姓名" && c2 != "学号") {
                    cout << "输入有误！请重新输入（放弃输入请输入exit）：";
                    cin >> c2;
                    if (c2 == "exit") {
                        flagout = true;
                        break;
                    }
                }
                if (flagout) break;
                if (c2 == "姓名") {
                    cout << "请输入学生姓名：";
                    string stuname;
                    cin >> stuname;
                    while (stunamemap.find(stuname) == stunamemap.end()) {
                        cout << "查无此人！" << endl;
                        cout << "请重新输入姓名（放弃输入请输入exit）：";
                        cin >> stuname;
                        if (stuname == "exit") {
                            flagout = true;
                            break;
                        }
                    }
                    if (!flagout) {
                        for (auto i : stunamemap[stuname]) {
                            cout << i;
                        }
                    }
                    break;
                }
                if (flagout) break;
                if (c2 == "学号") {
                    cout << "请输入学生学号：";
                    string stuno;
                    cin >> stuno;
                    while (stunomap.find(atoi(stuno.c_str())) == stunomap.end()) {
                        cout << "查无此人！" << endl;
                        cout << "请重新输入学号（放弃输入请输入exit）：";
                        cin >> stuno;
                        if (stuno == "exit") {
                            flagout = true;
                            break;
                        }
                    }
                    if (!flagout) {
                        cout << stunomap[atoi(stuno.c_str())];
                    }
                    break;
                }
                if (flagout) break;
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "输入错误！" << endl;
            // exit(0);
            break;
        }
    }
}

void menu() {
    cout << "请选择需要使用的功能。" << endl;
    cout << "1. 按各门课程成绩排序，并输出打印。" << endl;
    cout << "2. 计算每人的平均成绩，按平均成绩排序，并输出打印。" << endl;
    cout << "3. 求出各门课程的平均成绩、最高分、最低分、不及格人数、60-69分人数、70-79分人数、 80-89分人数、90分以上人数。" << endl;
    cout << "4. 根据姓名或学号查询某人的各门成绩。" << endl;
    cout << "5. 退出程序。" << endl;
}
