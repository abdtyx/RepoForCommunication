#include <iostream>
#include <valarray>

using namespace std;

typedef valarray<int> ArrayInt;
typedef pair<ArrayInt, ArrayInt> PairArray;

class Wine {
	private:
		// char label[50];
		string label;
		int number_of_years;
		PairArray p;
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
};

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
	p.first = a1;
	p.second = a2;
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
	p.first = a1;
	p.second = a2;
	delete [] arr1;
	delete [] arr2;
	return;
}

string Wine::Label() {
	return label;
}

int Wine::sum() {
	return p.second.sum();
}

void Wine::Show() {
	string fill8 = "        ";
	string fill4 = "    ";
	cout << "Wine: " << label << endl;
	cout << fill8 << "Year" << fill4 << "Bottles" << endl;
	for (int i = 0; i < number_of_years; i++) {
		cout << fill8 << p.first[i] << fill4 << p.second[i] << endl;
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
