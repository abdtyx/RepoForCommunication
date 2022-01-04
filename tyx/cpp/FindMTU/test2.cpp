#include <stdio.h>
#include <stdlib.h>

void mlc();

int main() {
    mlc();
    system("pause");
    return 0;
}

void mlc() {
    int ctr = 0;
    while(ctr++ < 1000000)
        int* tmp = (int*)malloc(4 * 1000);
        // int* tmp = new int[1000];
}