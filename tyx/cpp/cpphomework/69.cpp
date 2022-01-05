#include <iostream>
#include <valarray>

using namespace std;

typedef valarray<int> ArrayInt;
// typedef pair<ArrayInt, ArrayInt> PairArray;

class PairArray {
	private:
		ArrayInt first;
		ArrayInt second;
	public:
		void mod_first(ArrayInt a);
		void mod_second(ArrayInt a);
		ArrayInt& pfirst();
		ArrayInt& psecond();
};

void PairArray::mod_first(ArrayInt a) {
	first = a;
}

void PairArray::mod_second(ArrayInt a) {
	second = a;
}

ArrayInt& PairArray::pfirst() {
	return first;
}

ArrayInt& PairArray::psecond() {
	return second;
}

class Wine : private PairArray {
	private:
		// char label[50];
		string label;
		int number_of_years;
		// PairArray p;
	public:
		Wine();
		~Wine();
		// initialize label to l, number of years to y,
		// vintage years to yr[], bottles to bot[]
		Wine(const char* l, int y, const int yr[], const int bot[]);
		// initialize label to l, number of years to y,
		// create array objects of length y;
		Wine(const char* l, int y);
		/**
		 * @brief input
		 * first input an int y
		 * then input bottlesinfo
		 */
		void GetBottles();
		/**
		 * @return label
		 */
		string Label();
		/**
		 * @return sum years in p.second
		 */
		int sum();
		/**
		 * @brief show data
		 */
		void Show();

		// void modi_first(ArrayInt a);
		// void modi_second(ArrayInt a);
		// ArrayInt& gfirst();
		// ArrayInt& gsecond();
};

/*
void Wine::modi_first(ArrayInt a) {
	mod_first(a);
}

void Wine::modi_second(ArrayInt a) {
	mod_second(a);
}

ArrayInt& Wine::gfirst() {
	return pfirst();
}

ArrayInt& Wine::gsecond() {
	return psecond();
}
*/

Wine::Wine() {
	label.clear();
	number_of_years = 0;
}

Wine::~Wine() {
	label.clear();
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[]) {
	label = l;
	number_of_years = y;
	ArrayInt a1(yr, y);
	ArrayInt a2(bot, y);
	mod_first(a1);
	mod_second(a2);
	// p.first = a1;
	// p.second = a2;
}

Wine::Wine(const char* l, int y) {
	label = l;
	number_of_years = y;
}

void Wine::GetBottles() {
	int* arr1 = new int[number_of_years];
	int* arr2 = new int[number_of_years];
	// int ctr = 0;
	cout << "Enter " << label << " data for " << number_of_years << " year(s): " << endl;
	for (int i = 0; i < number_of_years; i++) {
		cout << "Enter year:\n";
		cin >> arr1[i];
		cout << "Enter bottles for that year:\n";
		cin >> arr2[i];
	}
	ArrayInt a1(arr1, number_of_years);
	ArrayInt a2(arr2, number_of_years);
	mod_first(a1);
	mod_second(a2);
	// p.first = a1;
	// p.second = a2;
	delete [] arr1;
	delete [] arr2;
	return;
}

string Wine::Label() {
	return label;
}

int Wine::sum() {
	return psecond().sum();
}

void Wine::Show() {
	string fill8 = "        ";
	string fill4 = "    ";
	cout << "Wine: " << label << endl;
	cout << fill8 << "Year" << fill4 << "Bottles" << endl;
	for (int i = 0; i < number_of_years; i++) {
		cout << fill8 << pfirst()[i] << fill4 << psecond()[i] << endl;
	}
	return;
}

int main( void ) {
	cout << "Enter name of wine:\n";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years:\n";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs); // store label, years, give arrays yrs elements
	holding.GetBottles(); // solicit input for year, bottle count
	holding.Show(); // display object contents

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {48, 60, 72};
	// create new object, initialize using data in arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() // use Label() method
		<< ": " << more.sum() << endl; // use sum() method
	cout << "Bye\n";
	return 0;
}
