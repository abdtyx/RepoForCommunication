#include <iostream>
#include <cstring>
using namespace std;

class Cow
{
    char name[20];
    char *hobby;
    double weight;

public:
    Cow();
    Cow(const char *nm, const char *ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow &operator=(const Cow &c);
    void getCow();
    // void _delete();
    void ShowCow() const; // display all cow data
};

Cow::Cow()
{
    for (int i = 0; i < 19; i++)
    {
        name[i] = '0';
    }
    hobby = new char[20];
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
    strcpy(name, nm);
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    hobby = new char[20];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
    hobby = NULL;
}

Cow &Cow::operator=(const Cow &c)
{
    delete[] hobby;
    hobby = new char[20];
    strcpy(this->name, c.name);
    strcpy(this->hobby, c.hobby);
    this->weight = c.weight;
    return *this;
}

void Cow::getCow()
{
    string a, b, c;
    char d[20];
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    strcpy(name, a.c_str());
    strcpy(hobby, b.c_str());
    strcpy(d, c.c_str());
    weight = strtod(d, NULL);
}

void Cow::ShowCow() const
{
    for (int i = 0; i < strlen(name); i++)
    {
        cout << name[i];
    }
    cout << " ";
    for (int j = 0; j < strlen(hobby); j++)
    {
        cout << hobby[j];
    }
    cout << " " << weight << endl;
}

int main()
{
    Cow c1, c2;
    c1.getCow();
    c2.getCow();
    Cow c3 = c1;
    Cow c4;
    c4 = c2;
    c3.ShowCow();
    c4.ShowCow();
    return 0;
}