#include <bits/stdc++.h>

using namespace std;

int main() {
    char dst[81], src[81];
    scanf("%[^\n]%*c", dst);
    scanf("%[^\n]", src);
    // printf("%s\n%s", dst, src);
    int i, flag = 0;
    for (i = 0; i < max(strlen(dst), strlen(src)); i++) {
        if (dst[i] != src[i]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("%d", i + 1);
    }
    else
        printf("0");
}