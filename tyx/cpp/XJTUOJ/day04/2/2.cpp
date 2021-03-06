#include <bits/stdc++.h>
#define e 1e5

using namespace std;

void dfs(int layer, int n);
bool check(int layer, int row);
int arr[13] = { 0 };
int ctr = 0;
int ans = 0;

int main() {
    int n;
    scanf("%d", &n);
    dfs(1, n);
    printf("%d", ans);
}

void dfs(int layer, int n) {
    if (layer > n)
    {
        ans++;
        if (ctr < 3)
        {
            for (int i = 0; i < n; i++)
            {
                i == 0 ? printf("%d", arr[i]) : printf(" %d", arr[i]);
            }
            printf("\n");
            ctr++;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(layer, i))
        {
            arr[layer - 1] = i;
            dfs(layer + 1, n);
        }
    }
}

bool check(int layer, int row) {
    for (int ii = 0; ii < layer - 1; ii++)
    {
        if (arr[ii] == row)
            return false;
        else if (layer + row == arr[ii] + ii + 1)
            return false;
        else if (layer - row == ii + 1 - arr[ii])
            return false;
    }
    return true;
}