#include <bits/stdc++.h>

using namespace std;

class largeInt {
    private:
        char arr[200];
    public:
        largeInt(char* a);
        largeInt operator+(largeInt bb) const;
        friend ostream& operator<<(ostream& output, largeInt a);
};

largeInt largeInt::operator+(largeInt bb) const {
    int lena = strlen(arr), lenb = strlen(bb.arr);
    char c[200], a[200], b[200];
    // 默认a比b长
    if (lena < lenb) {
        int l = lena;
        lena = lenb;
        lenb = l;
        strcpy(a, bb.arr);
        strcpy(b, arr);
    }
    else {
        strcpy(a, arr);
        strcpy(b, bb.arr);
    }
    // now length_a > length_b
    c[0] = '0';
    int r = 0;
    for (int i = lena; i > 0; i--) {
        if (lenb > 0) {
            int in = b[--lenb] + a[--lena] - '0' - '0' + r;
            if (in >= 10) {
                in -= 10;
                r = 1;
            }
            else {
                r = 0;
            }
            c[i] = in + '0';
        }
        else {
            int in = a[--lena] - '0' + r;
            if (in >= 10) {
                in -= 10;
                r = 1;
            }
            else {
                r = 0;
            }
            c[i] = in + '0';
        }
    }
    largeInt rtn(c);
    return rtn;
}

ostream& operator<<(ostream& output, largeInt a) {
    if (a.arr[0] == '0') {
        output << a.arr + 1;
        return output;
    }
    output << a.arr;
    return output;
}

largeInt::largeInt(char* a) {
    strcpy(arr, a);
}

int main(int argc, const char * argv[]) {
// insert code here...
char tmp1[200],tmp2[200];
std::cin >> tmp1;
std::cin >> tmp2;
largeInt int1(tmp1),int2(tmp2);
std::cout << int1+int2 <<std::endl;
return 0;
}