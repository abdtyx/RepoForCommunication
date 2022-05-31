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

        /**
         * @brief Construct a new Student object
         * 构造无名无学号的Student
         */
        Student() {
            stuno = 0;
            name = "";
            scores.clear();
            sumScore = 0;
        };
        
        /**
         * @brief Destroy the Student object
         * useless析构
         */
        ~Student() {
            stuno = 0;
            name = "";
            scores.clear();
            sumScore = 0;
        };

        /**
         * @brief Construct a new Student object
         * 构造学号s姓名n的Student
         * @param s 学号
         * @param n 姓名
         */
        Student(int s, string n) {
            stuno = s;
            name = n;
            scores.clear();
            sumScore = 0;
        }
        
        /**
         * @brief 输出学生信息
         * 
         * @param os 输出流引用
         * @param stu 需要输出的Student
         * @return ostream& 返回os输出流引用
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
         * 添加类型为pair(课程名，分数)的score
         * @param score 分数
         * @return true 添加成功
         * @return false 添加失败
         */
        bool append(pair<string, double> score) {
            scores.push_back(score);
            sumScore += score.second;
            return true;
        }

        /**
         * @brief 平均成绩
         * 计算平均成绩并返回
         * @return double 平均成绩
         */
        double avg() {
            return sumScore / scores.size();
        }
};

