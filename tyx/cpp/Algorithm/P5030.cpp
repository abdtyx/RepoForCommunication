#include <bits/stdc++.h>

using namespace std;

/**
 * dfs
 * 每放一个马，就对棋盘剩余位置进行封禁操作，然后dfs剩余位置，直到棋盘所有位置都被ban掉。
 * ban操作必须ban掉该马能吃的位置和会被其他马吃的其他马位置由于图像呈中心对称，可以证明，只需ban掉该马能吃的位置即可。
*/

#define MAX 205
int chess[MAX][MAX];

int main() {

    return 0;
}