#include <bits/stdc++.h>

using namespace std;

class Cd
{
private:
    friend class Classic;
    char* performers; // default 50
    char* label; // default 20
    int selections;
    double playtime;

public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    ~Cd();
    virtual void Report() const;
    Cd &operator=(const Cd &d);
};

Cd::Cd(const char* s1, const char *s2, int n, double x) {
	performers = new char[strlen(s1)];
	strcpy(performers, s1);
	label = new char[strlen(s2)];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d) {
	performers = new char[strlen(d.performers)];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label)];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd() {
	performers = new char[1];
	performers[0] = 0;
	label = new char[1];
	label[0] = 0;
	selections = 0;
	playtime = 0;
}

Cd::~Cd() {
        // performers[0] = 0;
	delete [] performers;
	// label[0] = 0;
	delete [] label;
	selections = 0;
        playtime = 0;
}

Cd& Cd::operator=(const Cd& d) {
	delete [] performers;
	performers = new char[strlen(d.performers)];
        strcpy(performers, d.performers);
	delete [] label;
	label = new char [strlen(d.label)];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
	return *this;
}

void Cd::Report() const {
	cout << performers << ',' << label << ',' << selections << ',' << playtime << endl;
}

class Classic: public Cd {
	private:
		char* primary_work; // default 50
	public:
		Classic(const char* s1, const char* s2, const char* s3, int n, double x);
		Classic(const Classic& c);
		Classic();
		~Classic();
		void Report() const;
		Classic& operator=(const Classic& c);
};

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x){
	primary_work = new char[strlen(s1)];
	strcpy(primary_work, s1);
	performers = new char[strlen(s2)];
	strcpy(performers, s2);
	label = new char[strlen(s3)];
        strcpy(label, s3);
        selections = n;
        playtime = x;
}

Classic::Classic(const Classic& c) {
	primary_work = new char[strlen(c.primary_work)];
	strcpy(primary_work, c.primary_work);
	performers = new char[strlen(c.performers)];
        strcpy(performers, c.performers);
	label = new char[strlen(c.label)];
	strcpy(label, c.label);
        selections = c.selections;
        playtime = c.playtime;
}

Classic::Classic() {
	primary_work = new char[1];
	primary_work[0] = 0;
	performers = new char[1];
	performers[0] = 0;
	label = new char[1];
	label[0] = 0;
	selections = 0;
	playtime = 0;
}

Classic::~Classic() {
        // primary_work[0] = 0;
	delete [] primary_work;
        // performers[0] = 0;
	delete [] performers;
        // label[0] = 0;
	delete [] label;
        selections = 0;
        playtime = 0;
}

Classic& Classic::operator=(const Classic& c) {
	delete [] primary_work;
	primary_work = new char[strlen(c.primary_work)];
        strcpy(primary_work, c.primary_work);
	delete [] performers;
	performers = new char[strlen(c.performers)];
        strcpy(performers, c.performers);
	delete [] label;
	label = new char[strlen(label)];
        strcpy(label, c.label);
        selections = c.selections;
        playtime = c.playtime;
	return *this;
}

void Classic::Report() const {
	cout << primary_work << ',' << performers << ',' << label << ',' << selections << ',' << playtime << endl;
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
