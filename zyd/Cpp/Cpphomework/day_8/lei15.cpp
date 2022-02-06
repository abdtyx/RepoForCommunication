#include <bits/stdc++.h>
#include <utility>
#include <valarray>

using namespace std;

typedef valarray<int> ArrayInt;
// typedef pair<ArrayInt, ArrayInt> PairArray;

class text
{
protected:
    ArrayInt a1;
    ArrayInt a2;

public:
    ArrayInt geta1(const ArrayInt a);
    ArrayInt geta2(const ArrayInt a);
    ArrayInt ga1();
    ArrayInt ga2();
};

ArrayInt text::geta1(const ArrayInt a)
{
    a1 = a;
    return a1;
}

ArrayInt text::geta2(const ArrayInt a)
{
    a2 = a;
    return a2;
}

ArrayInt ga1()
{
    return a1;
}

ArrayInt ga2()
{
    return a2;
}

class Wine : private text
{
private:
    // PairArray p;
    char name[50];
    int year;

public:
    Wine(const char *c, int y);
    Wine(const char *c, const int Y, const int *y, const int *b);
    void Show();
    void GetBottles();
    char *Label();
    int sum();
};

Wine::Wine(const char *c, int y)
{
    strcpy(name, c);
    year = y;
    ArrayInt a3(100);
    ArrayInt a4(100);
    geta1(a3);
    geta2(a4);
}
void Wine::GetBottles()
{
    cout << "Enter " << name << " data for " << year << " year(s): " << endl;
    for (int i = 0; i < year; i++)
    {
        cout << "Enter year: \n";
        cin >> ga1() [i];
        cout << "Enter bottles for that year: \n";
        cin >> ga2() [i];
    }
}

Wine::Wine(const char *c, const int Y, const int *y, const int *b)
{
    strcpy(name, c);
    year = Y;
    ArrayInt a3(100);
    ArrayInt a4(100);
    geta1(a3);
    geta2(a4);
    for (int i = 0; i < year; i++)
    {
        a1[i] = y[i];
    }
    for (int j = 0; j < year; j++)
    {
        a2[j] = b[j];
    }
}

void Wine::Show()
{
    cout << "Wine: " << name << endl;
    cout << "        "
         << "Year"
         << "    "
         << "Bottles" << endl;
    for (int i = 0; i < year; i++)
    {
        cout << "        " << a1[i] << "    " << a2[i] << endl;
    }
}

char *Wine::Label()
{
    return name;
}

int Wine::sum()
{
    int sum = 0;
    for (int i = 0; i < year; i++)
    {
        sum = a2[i] + sum;
    }
    return sum;
}

int main()
{
    cout << "Enter name of wine: \n";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: \n";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() //use Lable() method
         << ": " << more.sum() << endl;          // use sum() method
    cout << "Bye\n";
    return 0;
}