#include <bits/stdc++.h>


using namespace std;

typedef struct _Student {
	string Id;
	int cls;
	string name;
	double sc1, sc2, sc3, total;
} Student;

struct mycmp{
	bool operator() (Student a, Student b) {
		if (a.cls == b.cls) return a.total > b.total;
		return a.cls < b.cls;
	}
};

bool cmp(Student a, Student b) {
	if (a.cls == b.cls) return a.total > b.total;
	return a.cls < b.cls;
}

void menu();
void input();
void dlt();
void select();
void order();
void output();
void quit() {
	exit(0);
	return;
}

priority_queue<Student, vector<Student>, mycmp> stu;
vector<Student> Stu;
// bool is_sort = false;

int main() {
	menu();
	int control;
	while (cin >> control) {
		switch (control) {
			case 1:
				input();
				break;
			case 2:
				dlt();
				break;
			case 3:
				select();
				break;
			case 4:
				order();
				break;
			case 5:
				output();
				break;
			case 6:
				quit();

		}
	}
	return 0;
}

void menu() {
	cout << "1.input" << endl
		<< "2.delete" << endl
		<< "3.select" << endl
		<< "4.order" << endl
		<< "5.output" << endl
		<< "6.quit" << endl
		<< "please input your option" << endl;
	return;
}

void Send_mail(Student a) {
	cout << fixed << setprecision(1) << a.Id << ',' << a.cls << ',' << a.name << ',' << a.sc1 << ',' << a.sc2 << ',' << a.sc3 << ',' << a.total << endl;
	return;
}

void input() {
	Student tmp;
	cout << "Id ";
	cin >> tmp.Id;
	cout << "class ";
	cin >> tmp.cls;
	cout << "name ";
	cin >> tmp.name;
	cout << "score1 ";
	cin >> tmp.sc1;
	cout << "score2 ";
	cin >> tmp.sc2;
	cout << "score3 ";
	cin >> tmp.sc3;
	tmp.total = tmp.sc1 + tmp.sc2 + tmp.sc3;
	Stu.push_back(tmp);
	stu.push(tmp);
	string to_where;
	cout << "continue?" << endl;
	cin >> to_where;
	if (to_where == "yes")
		input();
	else
		menu();
	return;
}

void dlt() {
	string delete_what;
	cin >> delete_what;
	priority_queue<Student, vector<Student>, mycmp> tmp;
	vector<Student> Tmp;
	if (stu.size() > 1) {
		while (!stu.empty()) {
			Student temp = stu.top();
			stu.pop();
			if (delete_what != temp.Id && delete_what != temp.name) {
				// Send_mail(temp);
				tmp.push(temp);
			}
		}
	}
	else 
		return;
	if (Stu.size() > 1) {
		for (auto j : Stu) {
			if (delete_what != j.Id && delete_what != j.name) {
				Send_mail(j);
				Tmp.push_back(j);
			}
		}
	}
	else 
	       return;
	stu = tmp;
	Stu = Tmp;
	string to_where;
	cout << "continue?" << endl;
	cin >> to_where;
	if (to_where == "Yes")
		dlt();
	else
		menu();
	return;
}

void select() {
	// priority_queue<Student, vector<Student>, mycmp> tmp;
	string select_what;
	cin >> select_what;
	bool flag = true;
	/*
	while (!stu.empty()) {
		Student temp = stu.top();
		stu.pop();
		int clas = atoi(select_what.c_str());
		if (temp.Id == select_what || temp.cls == clas) {
			flag = false;
			Send_mail(temp);
		}
		tmp.push(temp);
	}
	*/
	int clas = atoi(select_what.c_str());
	for (auto j : Stu) {
		if (j.Id == select_what || j.cls == clas) {
			flag = false;
			Send_mail(j);
		}
	}
	if (flag)
		cout << "there is no eligible student" << endl;
	// stu = tmp;
	string to_where;
	cout << "continue?" << endl;
	cin >> to_where;
	if (to_where == "yes")
		select();
	else 
		menu();
	return;
}

void order() {
	/*
	priority_queue<Student, vector<Student>, mycmp> tmp = stu;
	vector<Student> Tmp;
	Tmp.clear();
	while (!tmp.empty()) {
		Tmp.push_back(tmp.top());
		tmp.pop();
	}
	Stu = Tmp;*/
	sort(&Stu[0], &Stu[Stu.size()], cmp);
	/*
	for (auto j : Stu) {
		Send_mail(j);
	}
	menu();
	return;
	*/
	output();
	return;
}

void output() {
	for (auto j : Stu) {
		Send_mail(j);
	}
	menu();
	return;
}
