#include <bits/stdc++.h>

using namespace std;

// stack.h -- class declaration for the stack ADT
typedef unsigned long Item;
class Stack
{
    private:
        enum
        {
            MAX = 10
        };            // constant specific to class
        Item *pitems; // holds stack items
        int size;     // number of elements in stack
        int top;      // index for top stack item
    public:
        Stack(int n = MAX); // creates stack with n elements
        Stack(const Stack &st);
        ~Stack();
        bool isempty() const;
        bool isfull() const;
        // push() returns false if stack already is full, true otherwise
        bool push(const Item &item); // add item to stack
        // pop() returns false if stack already is empty, true otherwise
        bool pop(Item &item); // pop top into item
        Stack &operator=(const Stack &st);
};

Stack::Stack(int n) {
    pitems = new Item[n];
    size = 0;
    top = -1;
}

Stack::Stack(const Stack& st) {
    pitems = new Item[MAX];
    size = st.size;
    top = st.top;
    for (int i = 0; i < st.size; i++) {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack() {
    delete [] pitems;
}

bool Stack::isempty() const {
    return !size;
}

bool Stack::isfull() const {
    if (top + 1 == MAX) {
        return true;
    }
    else 
        return false;
}

bool Stack::push(const Item& item) {
    if (isfull())
        return false;
    pitems[++top] = item;
    size++;
    return true;
}

bool Stack::pop(Item& item) {
    if (isempty())
        return false;
    item = pitems[top--];
    size--;
    return true;
}

Stack& Stack::operator=(const Stack& st) {
    delete [] pitems;
    pitems = new Item[MAX];
    size = st.size;
    top = st.top;
    for (int i = 0; i < st.size; i++) {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

int main() {
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order.\n" << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";
                      else 
                          st.push(po);
                      break;
            case 'p':
            case 'P': if (st.isempty())
                          cout << "stack already empty\n";
                      else {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                      }
                      break;
        }
        cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}