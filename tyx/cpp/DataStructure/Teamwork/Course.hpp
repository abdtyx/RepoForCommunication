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

/**
 * @brief 自定义比较函数
 * 按成绩从大到小排序，成绩一样时按照学号从小到大排序
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
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
        double maxScore;    // 最高分
        double minScore;    // 最低分
        int numStudent;     // 学生数量
        int numF;           // Failed
        int numD;           // 60-69
        int numC;           // 70-79
        int numB;           // 80-89
        int numA;           // 90-inf
        treap<P> t;         // P型的treap

        /**
         * @brief 统计分数区间
         * 
         * @param sc 分数
         */
        void statistic(double sc) {

            // 不及格
            if (sc < 60) {
                numF++;
            }

            // 及格
            else if (sc < 70) {
                numD++;
            }

            // 中等
            else if (sc < 80) {
                numC++;
            }

            // 良好
            else if (sc < 90) {
                numB++;
            }

            // 优秀
            else {
                numA++;
            }
        }

        /**
         * @brief Construct a new Course object
         * 禁止构造无名课程
         */
        Course() {
            cout << "禁止调用无名课程！必须传入课程名！" << endl;
            exit(0);
        }

        /**
         * @brief Destroy the Course object
         * useless析构
         */
        ~Course() {
            if (false) {
                cout << "析构Course类" << endl;
            }
        }

        /**
         * @brief Construct a new Course object
         * 有名称的课程，有效构造
         * @param n 
         */
        Course(string n) {
            name = n;
            sumScore = 0;
            maxScore = 0;
            minScore = 101;
            numStudent = 0;
            numF = numD = numC = numB = numA = 0;
            t = treap<P>(cmp);
        }
        
        /**
         * @brief 插入新学生
         * 插入的学生必须具有当前所有成绩
         * @param stu Student类
         * @return true 插入成功
         * @return false 插入失败
         */
        bool insertStudent(Student stu) {

            // 检测是否插入成功
            bool flag = false;
            // P p;

            // 插入时对Student.scores遍历找到对应于Course.name的课程
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

        /**
         * @brief 插入平均成绩的特殊函数
         * 仅用于插入平均成绩，是一种特判函数
         * @param s Student类
         * @param a 平均成绩
         */
        void insertavg(Student s, double a) {
            // P p;
            // p.first = s;
            // p.second = a;
            t.insert(make_pair(s, a));
        }

        /**
         * @brief 平均分函数
         * 计算并返回课程平均分
         * @return double 平均分
         */
        double avg() {
            return sumScore / numStudent;
        }

        /**
         * @brief 学生数量
         * 
         * @return int 学生数量
         */
        int size() {
            return numStudent;
        }

        /**
         * @brief 最高分
         * 
         * @return double 返回最高分
         */
        double maxscore() {
            return maxScore;
        }

        /**
         * @brief 最低分
         * 
         * @return double 返回最低分
         */
        double minscore() {
            return minScore;
        }

        /**
         * @brief 不及格学生数量
         * 
         * @return double 不及格学生数量
         */
        double numf() {
            return numF;
        }

        /**
         * @brief 及格学生数量
         * 
         * @return double 及格学生数量
         */
        double numd() {
            return numD;
        }

        /**
         * @brief 中等学生数量
         * 
         * @return double 中等学生数量
         */
        double numc() {
            return numC;
        }

        /**
         * @brief 良好学生数量
         * 
         * @return double 良好学生数量
         */
        double numb() {
            return numB;
        }

        /**
         * @brief 优秀学生数量
         * 
         * @return double 优秀学生数量
         */
        double numa() {
            return numA;
        }

        /**
         * @brief 打印所有学生
         * 打印按照该课程排序的所有学生信息
         */
        void printall() {
            t.output();
        }

        /**
         * @brief 打印课程统计数据
         * 打印课程平均分、最高分、最低分、不及格人数、及格人数、中等人数、良好人数和优秀人数
         */
        void printdata() {
            cout << "平均分\t最高分\t最低分\t不及格人数\t60-69分人数\t70-79分人数\t80-89分人数\t90分以上人数" << endl;
            cout << fixed << setprecision(2) << avg() << "\t\t" << maxscore() << '\t' << minscore() << '\t' << numf() << "\t\t" << numd() << "\t\t" << numc() << "\t\t" << numb() << "\t\t" << numa() << endl;
        }

        /**
         * @brief 课程名
         * 
         * @return string 返回课程名
         */
        string coursename() {
            return name;
        }
};