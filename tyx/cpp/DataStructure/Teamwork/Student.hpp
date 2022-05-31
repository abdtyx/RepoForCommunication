#ifndef _STUDENT_HPP
#define _STUDENT_HPP
#endif

#include <bits/stdc++.h>

// #ifndef _COURSE_HPP
// #include "Course.hpp"
// #endif

// #ifndef _TREAP_HPP
// #include "treap.hpp"
// #endif

using namespace std;

class Student{
    public:
        int stuno;                              // 学号
        string name;                            // 姓名
        vector<pair<string, double> > scores;   // [(学科，成绩)]
        double sumScore;
        Student() {
            stuno = 0;
            name = "";
            scores.clear();
            sumScore = 0;
        };
        ~Student() {
            stuno = 0;
            name = "";
            scores.clear();
            sumScore = 0;
        };
        Student(int s, string n) {
            stuno = s;
            name = n;
            scores.clear();
            sumScore = 0;
        }
        
        /**
         * @brief 输出学生信息
         * 
         * @param os 
         * @param stu 
         * @return ostream& 
         */
        friend ostream& operator <<(ostream& os, Student& stu) {
            os << stu.stuno << '\t' << stu.name;
            for (auto i : stu.scores) {
                os << '\t' << i.second;
            }
            os << "\t" << fixed << setprecision(2) << stu.avg();
            os << endl;
            return os;
        }
        
        /**
         * @brief 添加学科成绩
         * 
         * @param score 
         * @return true 
         * @return false 
         */
        bool append(pair<string, double> score) {
            scores.push_back(score);
            sumScore += score.second;
            return true;
        }

        double avg() {
            return sumScore / scores.size();
        }
};

