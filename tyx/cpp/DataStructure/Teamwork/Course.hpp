#ifndef _COURSE_HPP
#define _COURSE_HPP
#endif

#include <bits/stdc++.h>

#ifndef _TREAP_HPP
#include "treap.hpp"
#endif

#ifndef _STUDENT_HPP
#include "Student.hpp"
#endif

using namespace std;

typedef pair<Student, double> P;    // 学生，该课程成绩

inline bool cmp(P a, P b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second) 
        return a.first.stuno < b.first.stuno;
    else return false;
}

class Course {
    public:
        string name;        // 课程名
        double sumScore;    // 所有学生总分
        double maxScore;
        double minScore;
        int numStudent;
        int numF;   // Failed
        int numD;   // 60-69
        int numC;   // 70-79
        int numB;   // 80-89
        int numA;   // 90-inf
        treap<P> t;
        void statistic(double sc) {
            if (sc < 60) {
                numF++;
            }
            else if (sc < 70) {
                numD++;
            }
            else if (sc < 80) {
                numC++;
            }
            else if (sc < 90) {
                numB++;
            }
            else {
                numA++;
            }
        }
    
        Course() {
            cout << "禁止调用无名课程！必须传入课程名！" << endl;
            exit(0);
        }
        ~Course() {
            if (false) {
                cout << "析构Course类" << endl;
            }
        }
        Course(string n) {
            name = n;
            sumScore = 0;
            maxScore = 0;
            minScore = 101;
            numStudent = 0;
            numF = numD = numC = numB = numA = 0;
            t = treap<P>(cmp);
        }
        
        bool insertStudent(Student stu) {
            bool flag = false;
            // P p;
            for (auto i : stu.scores) {
                if (i.first == name) {
                    P p = make_pair(stu, i.second);
                    sumScore += i.second;
                    maxScore = max(maxScore, i.second);
                    minScore = min(minScore, i.second);
                    numStudent++;
                    statistic(p.second);
                    t.insert(p);
                    flag = true;
                    break;
                }
            }
            return flag;
        }

        void insertavg(Student s, double a) {
            // P p;
            // p.first = s;
            // p.second = a;
            t.insert(make_pair(s, a));
        }

        double avg() {
            return sumScore / numStudent;
        }

        int size() {
            return numStudent;
        }

        double maxscore() {
            return maxScore;
        }

        double minscore() {
            return minScore;
        }

        double numf() {
            return numF;
        }

        double numd() {
            return numD;
        }

        double numc() {
            return numC;
        }

        double numb() {
            return numB;
        }

        double numa() {
            return numA;
        }

        void printall() {
            t.output();
        }

        void printdata() {
            cout << "平均成绩\t最高分\t最低分\t不及格人数\t60-69分人数\t70-79分人数\t80-89分人数\t90分以上人数" << endl;
            cout << fixed << setprecision(2) << avg() << "\t\t" << maxscore() << '\t' << minscore() << '\t' << numf() << "\t\t" << numd() << "\t\t" << numc() << "\t\t" << numb() << "\t\t" << numa() << endl;
        }

        string coursename() {
            return name;
        }
};