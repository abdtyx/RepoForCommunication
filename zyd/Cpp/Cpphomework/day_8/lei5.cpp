#include <iostream>
using namespace std;
class Time
{
private:
    int hours;
    int minutes;

public:
    Time()
    {
        hours = minutes = 0;
    }
    Time(int h, int m = 0) : hours(h), minutes(m){};
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time &t, const Time &m);
    friend Time operator-(const Time &t, const Time &m);
    friend Time operator*(const Time &t, double m);
    friend Time operator*(double m, const Time &t)
    {
        return t * m;
    }
    friend ostream &operator<<(ostream &out, const Time &t);
};

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time operator+(const Time &t, const Time &m)
{
    Time sum;
    sum.minutes = m.minutes + t.minutes;
    sum.hours = m.hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time &t, const Time &m)
{
    Time diff;
    int t1, t2;
    t1 = t.minutes + 60 * t.hours;
    t2 = m.minutes + 60 * m.hours;
    diff.minutes = (t1 - t2) % 60;
    diff.hours = (t1 - t2) / 60;
    return diff;
}

Time operator*(const Time &t, double m)
{
    Time result;
    long tot = t.hours * m * 60 + t.minutes * m;
    result.minutes = tot % 60;
    result.hours = tot / 60;
    return result;
}

ostream &operator<<(ostream &out, const Time &t)
{
    out << t.hours << " hours, " << t.minutes << " minutes";
    return out;
}

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;
    return 0;
}
