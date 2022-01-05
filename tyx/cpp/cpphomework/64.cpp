#include <bits/stdc++.h>

using namespace std;

class Stock {
    private:
        char* company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() { total_val = shares * share_val; }
    public:
        Stock();
        Stock(const char* co, long n = 0, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;
        const Stock& topval(const Stock& s) const;
        friend ostream& operator<<(ostream& output, Stock& st);
};

Stock::Stock() {
    // company = "no name";
    company = new char[8];
    company[0] = 0;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr) {
    // company = co;
    company = new char[strlen(co)];
    strcpy(company, co);

    if (n < 0) {
        cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << "Number of shares purchased can't be negetive. " << "Transaction is aborted.\n";
    }
    else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << "Number of shares sold can't be negeative. " << "Transaction is aborted.\n";
    }
    else if (num > shares) {
        cout << "You can't sell more than you have! " << "Transaction is aborted.\n";
    }
    else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() const {
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);
    cout << "Company: " << company << " Shares: " << shares << endl;
    cout << "Share Price: $" << share_val;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << ' ';
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

ostream& operator<<(ostream& output, Stock& st) {
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);
    cout << "Company: " << st.company << " Shares: " << st.shares << endl;
    cout << "Share Price: $" << st.share_val;
    cout.precision(2);
    cout << " Total Worth: $" << st.total_val << ' ';
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
    return output;
}

const Stock& Stock::topval(const Stock& s) const {
    if (s.total_val > total_val)
        return s;
    else 
        return *this;
}

Stock::~Stock() {
    delete [] company;
}

const int STKS = 4;

int main() {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0), 
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++) {
        // stocks[st].show();
        cout << stocks[st];
    }
    const Stock* top = &stocks[10];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }
    cout << "\n\nMost valuable holding:\n";
    top->show();
    return 0;
}