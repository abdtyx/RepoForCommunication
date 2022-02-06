#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> a;
    int count = 0;
    ifstream ifs("in.txt", ofstream::in);
    if (!ifs)
    {
        cout << "读取文件失败" << endl;
        return 0;
    }
    ofstream ofs("text.txt", ofstream::app);
    if (!ofs)
    {
        ifs.close();
        cout << "备份文件打开失败" << endl;
        return 0;
    }
    string x;
    while (ifs >> x)
    {
        a.push_back(x);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        ofs << a[i];
    }
    ifs.close();
    ofs.close();
    return 0;
}