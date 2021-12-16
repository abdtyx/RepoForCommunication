// pe12_2.cpp
#include <bits/stdc++.h>

// #define CINLIM 100

using namespace std;

class String
{
    private:
        char* str;
        int len;
        // static int num_strings;
        static const int CINLIM = 80;
    public:
    // constructors and other methods
        String(const char * s);
        String();
        String(const String&);
        ~String();
        int length() const {return len;}
        void stringlow();
        void stringup();
        int has(const char ch) const;
    // overloaded operator methods
        String& operator=(const String&);
        String& operator=(const char*);
        char& operator[](int i);
        const char& operator[](int i) const;
        String& operator+(const String&) const;
    // overload operator friends
        friend String& operator+(const char*, const String& st2);
        friend bool operator<(const String& st, const String& st2);
        friend bool operator>(const String& st, const String& st2);
        friend bool operator==(const String& st, const String& st2);
        friend ostream& operator<< (ostream& os, const String& st);
        friend istream& operator>>(istream &is, String &st)
        {
            string tmp;
            getline(is, tmp);
            // char temp[CINLIM];
            delete [] st.str;
            st.len = tmp.size();
            st.str = new char[st.len + 1];
            strcpy(st.str, tmp.c_str());
            // is.get(temp, CINLIM, '\r');
            // if (is)
            // {
            //     st = temp;
            // }
            // while (is && is.get() != '\n')
            // {
            //     continue;
            // }
            is.clear();
            return is;
        }
    // static function
        static int HowMany();
};

// int String::HowMany() {
//     return num_strings;
// }

String::String(const char* s) {
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    // num_strings++;
}

String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    // num_strings++;
}

String::String(const String& st) {
    // num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String() {
    // --num_strings;
    delete [] str;
}

String& String::operator=(const String& st) {
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String& String::operator=(const char* s) {
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char& String::operator[](int i) {
    return str[i];
}

const char& String::operator[](int i) const {
    return str[i];
}

bool operator<(const String& st1, const String& st2) {
    return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2) {
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2) {
    return (strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st) {
    os << st.str;
    return os;
}

String& String::operator+(const String& st2) const {
    char dest[200] = "";
    strcat(dest, str);
    strcat(dest, st2.str);
    // String st3(dest);
    String* st3 = new String;
    *st3 = dest;
    return *st3;
}

String& operator+(const char* s, const String& st2) {
    char dest[200] = "";
    strcat(dest, s);
    strcat(dest, st2.str);
    // String st3(dest);
    String* st3 = new String;
    *st3 = dest;
    return *st3;
}

void String::stringlow() {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void String::stringup() {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

int String::has(const char ch) const{
    int ctr = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ch)
            ctr++;
    }
    return ctr;
}

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name:\n";
    String s3;
    cout << s2;              // overloaded << operator
    cin >> s3;               // overloaded >> operator
    s2 = ("My name is " + s3); // overloaded =, + operators
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup(); // converts string to uppercase
    cout << "The string " << s2 << "\ncontains " << s2.has('A')
         << " 'A' characters in it.\n";
    s1 = "red"; // String(const char *),
    // then String & operator=(const String&)
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light:\n";
    String ans;
    bool success = false;
    while (cin >> ans)
    {
        ans.stringlow(); // converts string to lowercase
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i]) // overloaded == operator
            {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye\n";
    return 0;
}
