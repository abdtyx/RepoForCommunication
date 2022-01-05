#include <bits/stdc++.h>

using namespace std;

class Person {
    public:
        string IdPerson;
        string Name;
        string Sex;
        string Birthday;
        string HomeAddress;
        Person();
        Person(string Person, string Name, string Sex, string Birthday, string HomeAddress);
        ~Person();
        Person(const Person& obj);
};

Person::Person() {
    IdPerson = "";
    Name = "";
    Sex  = "";
    Birthday = "";
    HomeAddress = "";
}

Person::Person(string Person, string Name, string Sex, string Birthday, string HomeAddress) {
    this->IdPerson = IdPerson;
    this->Name = Name;
    this->Sex = Sex;
    this->Birthday = Birthday;
    this->HomeAddress = HomeAddress;
}

Person::Person(const Person& obj) {
    IdPerson = obj.IdPerson;
    Name = obj.Name;
    Sex = obj.Sex;
    Birthday = obj.Birthday;
    HomeAddress = obj.HomeAddress;
}

Person::~Person() {
    IdPerson = "";
    Name = "";
    Sex  = "";
    Birthday = "";
    HomeAddress = "";
}

int main() {
    Person p;
    cin >> p.IdPerson >> p.Name >> p.Sex >> p.Birthday >> p.HomeAddress;
    cout << p.IdPerson << ' ' <<  p.Name << ' ' << p.Sex << ' ' << p.Birthday << ' ' << p.HomeAddress;
    return 0;
}