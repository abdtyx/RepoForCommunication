#include <bits/stdc++.h>

using namespace std;

class Sample {
	private:
		friend class Process;
		string name;
		int array[5];
	public:
		int ptr;
		Sample();
		void Insert(int i);
		void output();
};

class Process {
	public:
		void sort(Sample& a);
};

Sample::Sample() {
	memset(array, 0, sizeof(array));
	name.clear();
	ptr = 0;
}

void Sample::Insert(int i) {
	array[ptr++] = i;
}

void Sample::output() {
	for (int i = 0; i < ptr; i++) {
		if (i == 0)
			cout << array[i];
		else 
			cout << ' ' << array[i];
	}
}

void Process::sort(Sample& a) {
	for (int i = 0; i < a.ptr - 1; i++) {
		for (int j = 0; j < a.ptr - i - 1; j++) {
			if (a.array[j] > a.array[j + 1]) {
				int tmp = a.array[j];
				a.array[j] = a.array[j + 1];
				a.array[j + 1] = tmp;
			}
		}
	}
}

int main() {
	int temp;
	Sample a;
	for (int i = 0; i < 5; i++) {
		cin >> temp;
		a.Insert(temp);
	}
	Process p;
	p.sort(a);
	a.output();
	return 0;
}
