#include <iostream>
using namespace std;
int FindSmallestSum(int* a1, int* a2, int n)
{
    if (n == 0)
        return 0;
    int ans = 0x2f2f2f2f;
    for (int i = 0; i < n; i++) {
        int tmp = *(a1 + i) + *(a2 + i);
        if (tmp < ans)
            ans = tmp;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
int n; int* a1; int* a2;
cin >> n;
a1 = new int[n]; a2 = new int[n];
for (int i=0; i<n; i++) {
cin >> a1[i];
}
for (int i=0; i<n; i++) {
cin >> a2[i];
}
cout << FindSmallestSum(a1, a2, n) << endl;
return 0;
}