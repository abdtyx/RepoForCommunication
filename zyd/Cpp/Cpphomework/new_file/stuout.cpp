#include <bits/stdc++.h>
using namespace std;

int num = 0;
string a[3] = {"指标点1", "指标点2", "指标点3"};
string b[3] = {"课程目标1", "课程目标2", "课程目标3"};

int main()
{
    ofstream ofs("student2.txt", std::ofstream::out | std::ofstream::trunc);
    if (!ofs)
    {
        cout << "输出失败！" << endl;
    }
    ofs << "            课程目标对毕业要求指标点达成度分析" << endl;
    streampos sp1 = ofs.tellp();
    for (int i = 0; i < 3; i++)
    {
        ofs << b[i] << ": ";
        streampos sp2 = ofs.tellp();
        streampos sp3 = sp2 - sp1 + 2;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                ofs << a[j] << " "
                    << "0.29" << endl;
            }
            else
            {
                ofs.seekp(sp3, ios::cur);
                ofs << a[j] << " "
                    << "0.29" << endl;
                sp1 = ofs.tellp();
            }
        }
    }
    ofs.close();
}