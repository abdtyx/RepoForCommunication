#include <bits/stdc++.h>

/**
 * 目测bfs，要传当前的操作记录下去
 * bfs到全部为0之后跳出
 * 写9个操作函数
*/

typedef struct _Clock {
    int a, b, c, d, e, f, g, h, i;
} Clock;

Clock fun1(Clock ab);
Clock fun2(Clock ab);
Clock fun3(Clock ab);
Clock fun4(Clock ab);
Clock fun5(Clock ab);
Clock fun6(Clock ab);
Clock fun7(Clock ab);
Clock fun8(Clock ab);
Clock fun9(Clock ab);
bool solved(Clock ab);


using namespace std;

int main() {
    Clock clk;
    cin >> clk.a >> clk.b >> clk.c >> clk.d >> clk.e >> clk.f >> clk.g >> clk.h >> clk.i;
    clk.a = (clk.a / 3) & 3; clk.b = (clk.b / 3) & 3; clk.c = (clk.c / 3) & 3; clk.d = (clk.d / 3) & 3; clk.e = (clk.e / 3) & 3; clk.f = (clk.f / 3) & 3; clk.g = (clk.g / 3) & 3; clk.h = (clk.h / 3) & 3; clk.i = (clk.i / 3) & 3;
    pair<Clock, queue<int>> ans, tmp;
    ans.first = clk;
    queue<pair<Clock, queue<int> > > bfs;
    // bfs入队
    for (int i = 1; i <= 9; i++) {
        if (!ans.second.empty()) {
            ans.second.pop();
            ans.second.push(i);
        }
        else
            ans.second.push(i);
        bfs.push(ans);
    }
    // bfs搜索
    while (1) {
        tmp = bfs.front();
        bfs.pop();
        // solve
        int method = tmp.second.back();
        switch (method) {
        case 1:
            tmp.first = fun1(tmp.first);
            break;
        case 2:
            tmp.first = fun2(tmp.first);
            break;
        case 3:
            tmp.first = fun3(tmp.first);
            break;
        case 4:
            tmp.first = fun4(tmp.first);
            break;
        case 5:
            tmp.first = fun5(tmp.first);
            break;
        case 6:
            tmp.first = fun6(tmp.first);
            break;
        case 7:
            tmp.first = fun7(tmp.first);
            break;
        case 8:
            tmp.first = fun8(tmp.first);
            break;
        case 9:
            tmp.first = fun9(tmp.first);
            break;
        default:
            cout << "Wrong!";
            break;
        }
        if (solved(tmp.first))
            break;
        // 向下bfs一层
        for (int i = 1; i <= 9; i++) {
            if (i == 1) {
                tmp.second.push(i);
            }
            else {
                tmp.second.pop();
                tmp.second.push(i);
            }
            bfs.push(tmp);
        }
    }
    queue<int> answer = tmp.second;
    int ctr = 0;
    while (!answer.empty()) {
        if (ctr == 0) {
            cout << answer.front();
            answer.pop();
        }
        else {
            cout << " " << answer.front();
            answer.pop();
        }
    }
    return 0;
}


Clock fun1(Clock ab) {
    // ABDE
    ab.a = (ab.a + 1) & 3;
    ab.b = (ab.b + 1) & 3;
    ab.e = (ab.e + 1) & 3;
    ab.d = (ab.d + 1) & 3;
    return ab;
}

Clock fun2(Clock ab) {
    // ABC
    ab.a = (ab.a + 1) & 3;
    ab.b = (ab.b + 1) & 3;
    ab.c = (ab.c + 1) & 3;
    return ab;
}

Clock fun3(Clock ab) {
    // BCEF
    ab.b = (ab.b + 1) & 3;
    ab.c = (ab.c + 1) & 3;
    ab.e = (ab.e + 1) & 3;
    ab.f = (ab.f + 1) & 3;
    return ab;
}

Clock fun4(Clock ab) {
    // ADG
    ab.a = (ab.a + 1) & 3;
    ab.d = (ab.d + 1) & 3;
    ab.g = (ab.g + 1) & 3;
    return ab;
}

Clock fun5(Clock ab) {
    // BDEFH
    ab.b = (ab.b + 1) & 3;
    ab.d = (ab.d + 1) & 3;
    ab.e = (ab.e + 1) & 3;
    ab.f = (ab.f + 1) & 3;
    ab.h = (ab.h + 1) & 3;
    return ab;
}

Clock fun6(Clock ab) {
    // CFI
    ab.c = (ab.c + 1) & 3;
    ab.f = (ab.f + 1) & 3;
    ab.i = (ab.i + 1) & 3;
    return ab;
}

Clock fun7(Clock ab) {
    // DEGH
    ab.d = (ab.d + 1) & 3;
    ab.e = (ab.e + 1) & 3;
    ab.g = (ab.g + 1) & 3;
    ab.h = (ab.h + 1) & 3;
    return ab;
}

Clock fun8(Clock ab) {
    // GHI
    ab.g = (ab.g + 1) & 3;
    ab.h = (ab.h + 1) & 3;
    ab.i = (ab.i + 1) & 3;
    return ab;
}

Clock fun9(Clock ab) {
    // EFHI
    ab.e = (ab.e + 1) & 3;
    ab.f = (ab.f + 1) & 3;
    ab.h = (ab.h + 1) & 3;
    ab.i = (ab.i + 1) & 3;
    return ab;
}


bool solved(Clock ab) {
    if (!(ab.a | ab.b | ab.c | ab.d | ab.e | ab.f | ab.g | ab.h | ab.i)) {
        // 已解决
        return true;
    }
    else
        return false;
}