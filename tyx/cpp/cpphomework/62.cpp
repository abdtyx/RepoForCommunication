#include <bits/stdc++.h>

using namespace std;

class Cow {
    char name[20];
    char *hobby;
    double weight;
public:
    Cow();  // default constructor
    Cow(const char *nm, const char *ho, double wt); // constructor
    Cow(const Cow& c);  // copy constructor
    ~Cow();
    Cow &operator=(const Cow& c);
    void ShowCow() const; // display all cow data
};

Cow::Cow() {
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0;
}

Cow& Cow::operator=(const Cow& c) {
    int len = strlen(c.hobby);
    delete [] hobby;
    hobby = new char[len];
    strcpy(name, c.name);
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

Cow::Cow(const char* nm, const char* ho, double wt) {
    strcpy(name, nm);
    int len = strlen(ho);
    hobby = new char[len];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow& c) {
    strcpy(name, c.name);
    int len = strlen(c.hobby);
    hobby = new char(len);
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    // delete [] name;
    delete [] hobby;
    weight = 0;
}

void Cow::ShowCow() const {
    cout << name << ' ' << hobby << ' ' << weight << endl;
}

// void hobby_cin(char* hobby, double& weight);

int main() {
    char name[20];
    char* hobby = new char[20];
    double weight;
    cin >> name;
    cin.getline(hobby, 1);
    cin.getline(hobby, 20);
    // hobby_cin(hobby, weight);
    cin >> weight;
    Cow c1(name, hobby, weight);
    cin >> name;
    cin.getline(hobby, 1);
    cin.getline(hobby, 20);
    // hobby_cin(hobby, weight);
    cin >> weight;
    Cow c2(name, hobby, weight);
    Cow c3(c1);
    Cow c4 = c2;
    c3.ShowCow();
    c4.ShowCow();
    return 0;
}

/*
void hobby_cin(char* hobby, double& weight) {
    cin.getline(hobby, 20);
    cin >> weight;
}
*/