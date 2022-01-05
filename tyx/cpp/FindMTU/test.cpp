#include <bits/stdc++.h>
#define N 100
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

using namespace std;

int main() {
    FILE* fp = NULL;
    char* cmd = new char[512];
    // system("echo hello");
    sprintf(cmd, "ping -l 1472 -f 202.117.0.20");
    if ((fp = popen(cmd, "r")) != NULL) {
        while (1) {
            if (fgets(cmd, 100, fp) != NULL) {
                printf("%s", cmd);
            }
            // if (fscanf(fp, "%[^\n]", cmd) != -1)
            //     printf("%s", cmd);
            else
                break;
            // pclose(fp);
        }
    }
    // printf("%s", cmd);
    return 0;
}