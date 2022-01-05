#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    string IdPerson;
    string Name;
    string Sex;
    string Birthday;
    string HomeAddress;

public:
    Person(string _Id = "123", string _Name = "zyd", string _Sex = "man", string _Birthday = "2002.4.23", string _Home = "XJTU") : IdPerson(_Id), Name(_Name), Sex(_Sex), Birthday(_Birthday), HomeAddress(_Home){};
    void cperson()
    {
        cin >> IdPerson >> Name >> Sex >> Birthday >> HomeAddress;
    }
    void show()
    {
        cout << IdPerson << " " << Name << " " << Sex << " " << Birthday << " " << HomeAddress;
    }
    Person person(string a, string b, string c, string d, string e)
    {
        IdPerson = a;
        Name = b;
        Sex = c;
        Birthday = d;
        HomeAddress = e;
    }
    Person copyperson(const Person &a)
    {
        IdPerson = a.IdPerson;
        Name = a.Name;
        Sex = a.Sex;
        Birthday = a.Birthday;
        HomeAddress = a.HomeAddress;
    }
};

int main()
{
    Person p;
    p.cperson();
    p.show();
    return 0;
}