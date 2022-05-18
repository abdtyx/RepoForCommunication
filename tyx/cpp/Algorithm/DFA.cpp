#include <bits/stdc++.h>

using namespace std;

typedef struct _q {
    bool accept;    // 是否是接受状态
    string name;    // 当是接受状态时，该位置表示url对应的name
    map<string, struct _q*> son;    // map里面塞dfa各状态之间相连的边(Ex: *,123,user,profile)，指针表示该边到哪个状态，用指针是有必要的，如果用int，删除将变得复杂。
    // 复杂度考虑：如果url的每一块都是log复杂度，log(a)+log(b)+log(c)+log(d)<=log(url.size()^4/64)依然很小
    // struct _q* father;  可能没必要，这里放这个主要是在想删除的实现
    // 现考虑查询。先把url拆分成一个stack<string> s;  [d,c,b,a]; 每一步弹出栈顶，在map里面搜索x和*，然后往x和*的两条路走，递归进行。如果所有路线匹配失败dfa进入死状态，调用错误处理。
} q;