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

vector<Course> courses;                     // 所有课程的容器
map<int, Student> stunomap;                 // 学号——学生对应表
map<string, vector<Student> > stunamemap;   // 姓名——学生对应表

void menu();                                // 用户提示菜单

void head();                                // 表头

int main() {
    system("chcp 65001");                   // 将cmd设置为utf-8
    system("cls");                          // 清屏，美观

    // 用户输入提示
    cout << "学籍管理系统" << endl;
    cout << "============" << endl;

    // 设置浮点数输出精度
    cout << fixed << setprecision(2);

    // courses[0] - 平均成绩
    Course ct("平均成绩");
    courses.push_back(ct);

    // 课程数量
    int m;
    cout << "请输入课程数量" << endl;
    cin >> m;

    // 加强鲁棒性
    while (m < 1) {
        cout << "课程数量太少！请重新输入：";
        cin >> m;
    }

    // 往courses里面push带名称的课程，注意，不使用Course(string)构造函数是非法的，在Course.hpp中进行了限定
    for (int i = 0; i < m; i++) {
        cout << "请输入课程名：";
        string name;
        cin >> name;
        Course ctmp(name);
        courses.push_back(ctmp);
    }

    // 学生数量
    int n;
    cout << "请输入学生数量" << endl;
    cin >> n;

    // 加强鲁棒性
    while (n < 1) {
        cout << "学生数量太少！请重新输入：";
        cin >> n;
    }

    // 把学生信息push到两张map以及各个Course类里面
    for (int i = 0; i < n; i++) {
        cout << "请输入学生信息（学号、姓名、各科成绩）：";
        int s;
        string n;
        cin >> s >> n;                  // 学号和姓名
        Student stmp(s, n);
        for (int j = 1; j <= m; j++) {
            double dtmp;
            cin >> dtmp;                // 各科成绩
            stmp.append(make_pair(courses[j].coursename(), dtmp));      // 学生类内部存储[(学科，成绩)]类型的vector
            // courses[j].insertStudent(stmp);
        }

        // 分别insert到对应Course类中
        for (int j = 1; j <= m; j++) {
            courses[j].insertStudent(stmp);
        }

        // 更新平均成绩
        courses[0].insertavg(stmp, stmp.avg());

        // 更新学号和姓名的map
        stunomap.insert(make_pair(s, stmp));
        if (stunamemap.find(n) == stunamemap.end()) {
            // 新加入
            vector<Student> vtmp;
            vtmp.push_back(stmp);
            stunamemap[n] = vtmp;
        }
        else {
            // 已有，直接插入
            stunamemap[n].push_back(stmp);
        }
    }
    while (1) {
        menu();     // 输出彩蛋
        int c;      // 控制操作类型的变量
        cin >> c;

        switch (c)
        {
        case 1:
            while (1) {
                cout << "请输入课程名：";
                string coursename;
                cin >> coursename;

                // 用户输入exit直接跳出
                if (coursename == "exit") break;
                bool nameflag = true;

                // 搜索课程
                for (auto i : courses) {
                    if (i.name == coursename) {
                        nameflag = false;
                        head();             // 输出表头
                        i.printall();       // 输出course中按该course成绩排序的学生名单
                        break;
                    }
                }

                // 找不到@coursename的课程
                if (nameflag) cout << "找不到此课程，请重新输入（放弃输入请输入exit）：";
                else break;
            }
            break;
        case 2:
            head();         // 输出表头
            courses[0].printall();      // 按平均成绩排序的学生名单
            break;
        case 3:
            while (1) {
                cout << "请输入课程名：";
                string coursename;
                cin >> coursename;

                // 用户输入exit直接跳出
                if (coursename == "exit") break;
                bool nameflag = true;

                // 搜索课程
                for (auto i : courses) {
                    if (i.name == coursename) {
                        nameflag = false;
                        i.printdata();      // 这里不用输出表头，直接集成在Course.printdata()内部了，因为两个表头不一样
                        break;
                    }
                }

                // 找不到@coursename的课程
                if (nameflag) cout << "找不到此课程，请重新输入（放弃输入请输入exit）：";
                else break;
            }
            break;
        case 4:
            while (1) {

                cout << "希望通过姓名还是学号查询？输入 `name` or `stuno`" << endl;
                string c2;
                
                // 区分以name查询和以stuno查询
                cin >> c2;
                bool flagout = false;   // 查询到exit跳出的flag
                
                while (c2 != "name" && c2 != "stuno") {
                    cout << "输入有误！请重新输入（放弃输入请输入exit）：";
                    cin >> c2;
                    if (c2 == "exit") {
                        flagout = true;
                        break;
                    }
                }

                if (flagout) break;

                // 以name查询
                if (c2 == "name") {
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
                    // 查到@name
                    if (!flagout) {
                        head();
                        for (auto i : stunamemap[stuname]) {
                            cout << i;
                        }
                    }
                    break;
                }

                if (flagout) break;

                if (c2 == "stuno") {
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
                    // 查到stuno
                    if (!flagout) {
                        head();
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

/**
 * @brief 菜单函数
 * 输出菜单
 */
void menu() {
    cout << "请选择需要使用的功能。" << endl;
    cout << "1. 按各门课程成绩排序，并输出打印。" << endl;
    cout << "2. 计算每人的平均成绩，按平均成绩排序，并输出打印。" << endl;
    cout << "3. 求出各门课程的平均成绩、最高分、最低分、不及格人数、60-69分人数、70-79分人数、 80-89分人数、90分以上人数。" << endl;
    cout << "4. 根据姓名或学号查询某人的各门成绩。" << endl;
    cout << "5. 退出程序。" << endl;
}

/**
 * @brief 表头函数
 * 输出表头
 */
void head() {
    cout << "学号" << "\t" << "姓名";
    for (auto i : courses) {
        if (i.name != "平均分") cout << "\t" << i.name;
    }
    cout << "\t" << "平均成绩" << endl;
}