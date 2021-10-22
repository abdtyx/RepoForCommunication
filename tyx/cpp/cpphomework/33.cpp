#include <stdio.h>
#include <string.h>

int main() {
    char str[81];
    scanf("%[^\n]", str);
    char ch;
    scanf("%c", &ch);
    scanf("%c", &ch);
    if (strchr(str, ch) != NULL) {
        int ans = strchr(str, ch) - str + 1;
        printf("%d", ans);
    }
    else 
        printf("0");
}