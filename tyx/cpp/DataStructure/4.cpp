#include <iostream>
#include <string.h>

using namespace std;

int main() {
    char arr1[1005];
    memset(arr1, 0, 1005);
    // cin >> arr1;
    cin.get(arr1, 1005);
    int front = -1, back = strlen(arr1);
    while(arr1[++front] == ' ');
    while(arr1[--back] == ' ');
    for (int i = front; i <= back; i++) cout << arr1[i];
    return 0;
}