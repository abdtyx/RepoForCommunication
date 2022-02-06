#include <bits/stdc++.h>
using namespace std;

class Cd
{
private:
    friend class Classic;
    char *performers;
    char *label;
    int selections;
    double playtime;

public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    ~Cd();
    virtual void Report() const;
    Cd &operator=(const Cd &d);
    // friend void Bravo(const Cd &disk);
};

class Classic : public Cd
{
private:
    char *Table;

public:
    Classic(const char *s1, const char *s2, const char *s3, int n, double x);
    Classic(const Classic &d);
    Classic();
    ~Classic();
    Classic &operator=(const Classic &d);
    void Report() const;
    // friend void Bravo(const Classic &disk);
};

Cd::Cd()
{
    performers = new char[50];
    label = new char[20];
    for (int i = 0; i < 49; i++)
    {
        performers[i] = 0;
    }
    for (int i = 0; i < 19; i++)
    {
        label[i] = 0;
    }
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers = new char[50];
    label = new char[20];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd &d)
{
    performers = new char[50];
    label = new char[20];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
    // performers[0] = 0;
    // label[0] = 0;
    selections = 0;
    playtime = 0.0;
}

void Cd::Report() const
{
    cout << performers << "," << label << "," << selections << "," << playtime << endl;
}

Cd &Cd::operator=(const Cd &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char *s1, const char *s2, const char *s3, int n, double x)
{
    performers = new char[50];
    label = new char[20];
    Table = new char[50];
    strcpy(Table, s1);
    strcpy(performers, s2);
    strcpy(label, s3);
    selections = n;
    playtime = x;
}

Classic::Classic(const Classic &d)
{
    // delete[] performers;
    // delete[] label;
    // delete[] Table;
    performers = new char[50];
    label = new char[20];
    Table = new char[50];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    strcpy(Table, d.Table);
    selections = d.selections;
    playtime = d.playtime;
}

Classic::Classic()
{
    performers = new char[50];
    label = new char[20];
    Table = new char[50];
    for (int i = 0; i < 49; i++)
    {
        performers[i] = 0;
    }
    for (int i = 0; i < 19; i++)
    {
        label[i] = 0;
    }
    for (int i = 0; i < 49; i++)
    {
        Table[i] = 0;
    }
    selections = 0;
    playtime = 0.0;
}

Classic::~Classic()
{
    delete[] Table;
    selections = 0;
    playtime = 0.0;
}

Classic &Classic::operator=(const Classic &d)
{
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    strcpy(Table, d.Table);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

void Classic::Report() const
{
    cout << Table << "," << performers << "," << label << "," << selections << "," << playtime << endl;
}

void Bravo(const Cd &disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: "; //注意此处冒号后有一个空格
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd &disk)
{
    disk.Report();
}