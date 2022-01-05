
#include <iostream>
#include <string>
#include <valarray>
using namespace std;
int main()
{
    valarray<int> a1{1, 2, 3};
    valarray<int> a2{4, 5, 6};
    pair<valarray<int>, valarray<int>> p;
    p = make_pair(a1, a2);
    cout << p.second[2] << endl;
    return 0;
}