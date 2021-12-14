#include <bits/stdc++.h>

using namespace std;

class Cow {
    char name[20];
    char *hobby;
    double weight;
public:
    Cow();
    Cow(const char *nm, const char *ho, double wt);
    Cow(const Cow& c);
    ~Cow();
    Cow &operator=(const Cow& c);
    void ShowCow() const; // display all cow data
};

Cow::Cow() {
    // delete [] name;
    // delete hobby;
    // new(name) char[20];
    // new(hobby) char*;
    weight = 0;
}

Cow& Cow::operator=(const Cow& c) {
    this->hobby = c.hobby;
    strcpy(this->name, c.name);
    this->weight = c.weight;
    return *this;
}

Cow::Cow(const char* nm, const char* ho, double wt) {
    strcpy(this->name, nm);
    // this->hobby = ho;
    // strcpy(this->hobby, ho);
    this->hobby = (char*)ho;
    weight = wt;
}

Cow::Cow(const Cow& c) {
    this->hobby = c.hobby;
    strcpy(this->name, c.name);
    this->weight = c.weight;
}

Cow::~Cow() {
    // delete [] name;
    // delete hobby;
    weight = 0;
}

void Cow::ShowCow() const {
    cout << name << ' ' << hobby << ' ' << weight << endl;
}

int main() {
    char name1[20];
    char name2[20];
    char hobby1[100];
    char hobby2[100];
    // char* hobby1, * hobby2;
    double weight1;
    double weight2;
    cin >> name1 >> hobby1 >> weight1;
    Cow c1(name1, hobby1, weight1);
    cin >> name2 >> hobby2 >> weight2;
    Cow c2(name2, hobby2, weight2);
    Cow c3(c1);
    Cow c4 = c2;
    c3.ShowCow();
    c4.ShowCow();
    return 0;
}