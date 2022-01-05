#include <bits/stdc++.h>
using namespace std;

class Stock
{
private:
    char *com;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }

public:
    Stock();
    Stock(const string &co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    // void show() const;
    friend ostream &operator<<(ostream &ot, const Stock &st);
    const Stock &topval(const Stock &s) const;
};

Stock::Stock()
{
    com = new char[20];
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const string &co, long n, double pr)
{
    com = new char[20];
    strcpy(com, co.c_str());
    if (n < 0)
    {
        cout << "Numberof shares can't be negative; " << com << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
        share_val = pr;
        set_tot();
    }
}

Stock::~Stock()
{
    delete[] com;
}

const Stock &Stock::topval(const Stock &s) const
{
    if (s.total_val > total_val)
    {
        return s;
    }
    else
    {
        return *this;
    }
}

ostream &operator<<(ostream &ot, const Stock &st)
{
    ios_base::fmtflags orig = ot.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = ot.precision(3);
    ot << "Company: " << st.com << " Shares: " << st.shares << '\n';
    ot << "Share Price: $" << st.share_val;
    ot.precision(2);
    ot << " Total Worth: $" << st.total_val;
    // ot << "Total Worth: $ "
    ot.setf(orig, ios_base::floatfield);
    ot.precision(prec);
    return ot;
}

const int STKS = 4;
int main()
{
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)};
    cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; st++)
    {
        cout << stocks[st];
        if (st != STKS - 1)
        {
            cout << " ";
        }
    }
    cout << "\n";
    const Stock *top = &stocks[0];
    for (st = 1; st < STKS; st++)
    {
        top = &top->topval(stocks[st]);
    }
    cout << "\nMost valuable holding:\n";
    cout << *top;
    return 0;
}