#include <fstream>
#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int score;

public:
    Student(string n = "a", int s = 0) : name(n), score(s){};
    void show()
    {
        cout << name << " " << score;
    }
    string getname()
    {
        return name;
    }
};

int main()
{
    Student s;
    ifstream ifs("in.txt", ifstream::in);
    if (!ifs)
    {
        cout << "读取文件失败" << endl;
        return 0;
    }
    ifs.seekg(0, ios::end);
    int R = ifs.tellg();
    ifs.seekg(0, ios::beg);
    // for (int i=ifs.seekg(7);i<=ifs.seekg())
    // cout << ifs.rdbuf() << endl;
    // ifs.read(reinterpret_cast<char *>(&s.getname()), sizeof(string));
    s.show();
}
