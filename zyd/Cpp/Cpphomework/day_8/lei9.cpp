#include <bits/stdc++.h>
using namespace std;
class String
{
private:
    char *str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    //constructors and other methods
    String(const char *s);
    String();
    String(const String &);
    ~String();
    int length() const { return len; }
    //overloaded operator methods
    String &operator=(const String &);
    String &operator=(const char *);
    String &operator+(const String &s);
    // String &operattor+(const char *);
    char &operator[](int i);
    const char &operator[](int i) const;
    //overloaded operator friends
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    friend bool operator==(const String &st, const String &st2);
    friend bool operator<(const String &st, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend String &operator+(const char *str, String &st);
    //statuc function
    void stringlow();
    void stringup();
    int has(const char c);
};
// intitializing static class member

int String::num_strings = 0;

// static method

//class methods
String::String(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    // delete[] str;
    // 目前真不会了，让我再好好学学
}

String &String::operator=(const String &s)
{
    if (this == &s)
    {
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

String &String::operator=(const char *s)
{
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char &String::operator[](int i)
{
    return str[i];
}

const char &String ::operator[](int i) const
{
    return str[i];
}

String &String ::operator+(const String &s)
{
    memcpy(str + len, s.str, s.len);
    len = strlen(s.str);
    return *this;
}

ostream &operator<<(ostream &out, const String &s)
{
    out << s.str;
    return out;
}

istream &operator>>(istream &is, String &st)
{
    string s;
    getline(cin, s);
    strcpy(st.str, s.c_str());
    st.len = strlen(st.str);
    st.str[st.len] = '\0';
    is.clear();
    return is;
}

bool operator==(const String &st1, const String &st2)
{
    return (strcmp(st1.str, st2.str) == 0);
}

String &operator+(const char *s, String &st)
{
    char a[100] = "";
    strcpy(a, s);
    int len2 = strlen(a);
    memcpy(a + len2, st.str, st.len);
    delete[] st.str;
    st.str = new char[100];
    strcpy(st.str, a);
    st.len = strlen(st.str);
    st.str[st.len] = '\0';
    return st;
}

void String::stringlow()
{
    int len2 = strlen(str);
    len = len2;
    for (int i = 0; i < len2; i++)
    {
        if (str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] = str[i] + 'a' - 'A';
        }
    }
}

void String::stringup()
{
    int len2 = strlen(str);
    // len = len2;
    for (int i = 0; i < len2; i++)
    {
        if (str[i] <= 'z' && str[i] >= 'a')
        {
            str[i] = str[i] + 'A' - 'a';
        }
    }
}

int String::has(const char c)
{
    int len2 = strlen(str);
    int n = 0;
    for (int i = 0; i < len2; i++)
    {
        if (str[i] == c)
        {
            n++;
        }
    }
    return n;
}

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name:\n";
    String s3;
    cout << s2;              // overloaded << operator
    cin >> s3;               // overloaded >> operator
    s2 = "My name is Fretta Farbo"; // overloaded =, + operators
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