#include <iostream>
#include <cstring>
using namespace std;

class Sample
{
private:
    char name[20];
    int A[20];

public:
    Sample()
    {
        name[0] = 0;
        for (int i = 0; i < 20; i++)
        {
            A[i] = 0;
        }
    }
    friend class Process;
};

class Process
{
public:
    Sample c;
    void bubble()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (c.A[j] > c.A[j + 1])
                {
                    int b;
                    b = c.A[j];
                    c.A[j] = c.A[j + 1];
                    c.A[j + 1] = b;
                }
            }
        }
    }
    void input()
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> c.A[i];
        }
    }
    void output()
    {
        for (int i = 0; i < 5; i++)
        {
            i == 0 ? cout << c.A[i] : cout << " " << c.A[i];
        }
    }
};

int main()
{
    Process s;
    s.input();
    s.bubble();
    s.output();
    return 0;
}