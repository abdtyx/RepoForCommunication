#include <iostream>
#include <cstring>
using namespace std;

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
    Stack(); // creates stack with n elements
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

Stack::Stack()
{
    pitems = new Item[MAX];
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item &item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
        return false;
    }
}

Stack::~Stack()
{
    delete[] pitems;
}

Stack &Stack::operator=(const Stack &st)
{
    delete[] pitems;
    pitems = new Item[MAX];
    top = st.top;
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

int main()
{
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a uurchase order,\n"
         << "p to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
        {
            continue;
        }
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
        case 'A':
        case 'a':
            cout << "Enter a PO number to add: ";
            cin >> po;
            if (st.isfull())
            {
                cout << "stack already full\n";
            }
            else
            {
                st.push(po);
            }
            break;
        case 'p':
        case 'P':
            if (st.isempty())
            {
                cout << "stack already empty\n";
            }
            else
            {
                st.pop(po);
                cout << "PO #" << po << " popped\n";
            }
            break;
        }
        cout << "Please enter A to add a purhase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}