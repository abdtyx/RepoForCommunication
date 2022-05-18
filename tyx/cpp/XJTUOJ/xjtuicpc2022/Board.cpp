#include <bits/stdc++.h>
#define MAXN 100
// #define p 998244353

using namespace std;

typedef long long int ll;

ll n, a[MAXN], ans = 0, t[MAXN];
// 二进制枚举
void binary_enumeration() {
    for (int mask = 0, tot = 1<<n; mask < tot; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask>>i) & 1) sum += a[i];
        }
        if (sum == 0) ans++;
    }
}

// 取模
// a > 0   a % p
// a < 0   a % p + p
// p < 0   a % |p|

// 除法取模
// a / b mod p = a * b^-1 mod p
//                   b^p-2

// 指数取模
// a^p-1 mod p = 1
// a^b mod p = a^(b mod p - 1) mod p

// 二分查找
bool check(int mid) {
    if (1) return 1;
}
int bsearch_1(int l, int r, int x) {
    // 可取mid
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
int bsearch_2(int l, int r, int x) {
    // 不取mid
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
// upperbound
inline int lower_bound(int a[], int l, int r, int x) {
    // 升序
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
// lowerbound
inline int upper_bound(int a[], int l, int r, int x) {
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

ll pow_mod(ll a, ll e, ll p) {
    if (e == 0) return 1;
    ll resby2 = pow_mod(a, e / 2, p);
    return resby2 * resby2 % p * ((e & 1) ? a : 1) % p;
}

// merge_sort
void sort(int a[], int l, int r) {
    if (r - l > 1) {
        int mid = (l + r) / 2;
        sort(a, l, mid);
        sort(a, mid, r);
        // merge(a, l, mid, r);
    }
}
void merge(int ll, int rr) {
  // 用来把 a 数组 [ll, rr - 1] 这一区间的数排序。 t
  // 数组是临时存放有序的版本用的。
  if (rr - ll <= 1) return;
  int mid = ll + ((rr - ll) >> 1);
  merge(ll, mid);
  merge(mid, rr);
  int p = ll, q = mid, s = ll;
  while (s < rr) {
    if (p >= mid || (q < rr && a[p] > a[q])) {
      t[s++] = a[q++];
      // ans += mid - p;
    } else
      t[s++] = a[p++];
  }
  for (int i = ll; i < rr; ++i) a[i] = t[i];
}

// 背包dp
// f[i][j]表示拿了第i件物品后用了j容量
// f[i][j]=max{f[i-1][j-v[i]]+w[i], f[i-1][j]}
// f[0][0]=0;
// 空间优化
void backpack() {
    int v[100], w[100], V = MAXN;
    int cur[100], lst[100];
    // 两行
    for (int i = 0; i < n; ++i) {
        for (int j = 0; i < v[i]; ++j) cur[j] = lst[j];
        for (int j = v[i]; j <= V; ++j) {
            cur[j] = max(lst[j], lst[j - v[i]] + w[i]);
        }
        for (int j = 0; j <= V; j++) lst[j] = cur[j];
    }
    // 一行
    int f[100];
    for (int i = 0; i < n; ++i)
        for (int j = V; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    // 完全背包
    for (int i = 0; i < n; ++i)
        for (int j = V; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    for (int i = 0; i < n; ++i)
        for (int j = v[i]; j <= V; ++j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
}

// 树状数组
ll c[100005];
ll lowbit(ll x) {return x & (-x);}

namespace 单改区查_or_区改单查 {
    void updata(ll pos, ll data) {
        while (pos <= n) {
            c[pos] += data;
            pos += lowbit(pos);
        }
    }

    ll getsum(ll r) {
        // 1到r的和
        ll ans = 0;
        while (r > 0) {
            ans += c[r];
            r -= lowbit(r);
        }
        return ans;
    }

    void solve1() {
        // 单改区查
        // 1 x k 含义：将第 x 个数加上 k
        // 2 x y 含义：输出区间 [x,y] 内每个数的和
        ll m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            updata(i, a[i]);
        }
        for (ll i = 1; i <= m; i++) {
            ll swi, l, r;
            cin >> swi >> l >> r;
            if (swi == 1) {
                updata(l, r);
                a[l] += r;
            }
            if (swi == 2) {
                cout << getsum(r), getsum(l - 1) << '\n';
            }
        }
        return;
    }

    void solve2() {
        // 区改单查
        // 1 x y k 含义：将区间 [x,y] 内每个数加上 k；
        // 2 x 含义：输出第 x 个数的值。
        ll m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            updata(i, a[i] - a[i - 1]);
        }
        for (ll i = 1; i <= m; i++) {
            ll where;
            cin >> where;
            if (where == 1) {
                ll x, y, k;
                cin >> x >> y >> k;
                updata(x, k);
                updata(y + 1, -k);
            }
            if (where == 2) {
                ll q;
                cin >> q;
                cout << getsum(q) << '\n';
            }
        }
        return;
    }
}

namespace 区改区查 {
    ll lowbit(ll x) {return x & (-x);}
    ll c1[MAXN], c2[MAXN];

    void updata(ll i, ll k) {
        ll x = i;
        while (i <= n) {
            c1[i] += k;
            c2[i] += k * (x - 1);
            i += lowbit(i);
        }
    }

    ll getsum(ll i) {
        ll ans = 0, x = i;
        while (i > 0) {
            ans += x * c1[i] - c2[i];
            i -= lowbit(i);
        }
        return ans;
    }

    void solve() {
        ll m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            updata(i, a[i] - a[i - 1]);
        }
        for (ll i = 1; i <= m; i++) {
            ll where;
            cin >> where;
            if (where == 1) {
                ll x, y, k;
                cin >> x >> y >> k;
                updata(x, k);
                updata(y + 1, -k);
            }
            if (where == 2) {
                ll x, y;
                cin >> x >> y;
                cout << getsum(y) - getsum(x - 1) << '\n';
            }
        }
        return;
    }
}

// 线段树
int sum[MAXN], tag[MAXN];
namespace 单点修改区间查询 {
// 单点修改
    void add(int p, int k, int l, int r, int x) {
        sum[k] += x;
        if (l == r) return;
        int m = (l + r) >> 1;
        if (p <= m) {
            add(p, k << 1, l, m, x);
        }
        else {
            add(p, (k << 1) | 1, m + 1, r, x);
        }
    }
    // 区间查询
    int ask(int a, int b, int k, int l, int r) {
        if (a <= l && r <= b) {
            return sum[k];
        }
        int m = (l + r) >> 1, ans = 0;
        if (a <= m) ans += ask(a, b, k << 1, l, m);
        if (b > m) ans += ask(a, b, (k << 1) | 1, m + 1, r);
        return ans;
    }
    
    void solve() {
        int n, m;
        cin >> n >> m;
        // 1 x k 给x加k
        // 2 x y 查询x到y的和
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            add(i + 1, 1, 1, n, tmp);
        }
        for (int i = 0; i < m; i++) {
            int s, x, y, k;
            cin >> s;
            if (s == 1) {
                cin >> x >> k;
                add(x, 1, 1, n, k);
            }
            if (s == 2) {
                cin >> x >> y;
                cout << ask(x, y, 1, 1, n) << endl;
            }
        }
        return;
    }
}

namespace 区间修改区间查询 {
    ll ls(ll k) {return k << 1;}
    ll rs(ll k) {return (k << 1) | 1;}

    /**
     * @brief 
     * 
     * @param k 当前线段树结点编号
     * @param x 左段长度
     * @param y 右段长度
     */
    void pushdown(ll k, ll x, ll y) {
        if (tag[k]) {
            sum[ls(k)] += tag[k] * x;
            sum[rs(k)] += tag[k] * y;
            tag[ls(k)] += tag[k];
            tag[rs(k)] += tag[k];
            tag[k] = 0;
        }
    }

    void pushup(ll k) {
        sum[k] = sum[ls(k)] + sum[rs(k)];
    }

    // 区间修改
    /**
     * @brief 
     * 
     * @param a 区间下界
     * @param b 区间上界
     * @param k 当前线段树结点编号
     * @param l 当前线段树结点左
     * @param r 当前线段树结点右
     * @param x 需要加的数
     */
    void add(ll a, ll b, ll k, ll l, ll r, ll x) {
        if (a <= l && r <= b) {
            sum[k] += (r - l + 1) * x;
            tag[k] += x;
            return;
        }
        ll m = (l + r) >> 1;
        pushdown(k, m - l + 1, r - m);
        if (a <= m) add(a, b, ls(k), l, m, x);
        if (b > m) add(a, b, rs(k), m + 1, r, x);
        pushup(k);
    }

    // 区间查询
    /**
     * @brief 
     * 
     * @param a 查询区间下界
     * @param b 查询区间上界
     * @param k 当前线段树结点编号
     * @param l 当前线段树结点左
     * @param r 当前线段树结点右
     * @return ll 结果
     */
    ll ask(ll a, ll b, ll k, ll l, ll r) {
        if (a <= l && r <= b) {
            return sum[k];
        }
        ll m = (l + r) >> 1;
        ll ans = 0;
        pushdown(k, m - l + 1, r - m);
        if (a <= m) ans += ask(a, b, ls(k), l, m);
        if (b > m) ans += ask(a, b, rs(k), m + 1, r);
        return ans;
    }

    void solve() {
        ll m;
        cin >> n >> m;
        // 1 x y k 给x到y加上k
        // 2 x y 输出x到y的和
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            add(i + 1, i + 1, 1, 1, n, tmp);
        }
        for (ll i = 0; i < m; i++) {
            ll s, x, y, k;
            cin >> s;
            if (s == 1) {
                cin >> x >> y >> k;
                add(x, y, 1, 1, n, k);
            }
            if (s == 2) {
                cin >> x >> y;
                cout << ask(x, y, 1, 1, n) << endl;
            }
        }
        return;
    }
}

namespace 区间乘法 {
    ll n, sum[MAXN], ta[MAXN], tm[MAXN];
    ll p = 571373;

    ll ls(ll k) {return k << 1;}
    ll rs(ll k) {return (k << 1) | 1;}

    /**
     * @brief 
     * 
     * @param k 当前线段树结点编号
     * @param x 左段长度
     * @param y 右段长度
     */
    void pushdown(ll k, ll x, ll y) {
        if (ta[k] || tm[k] != 1) {
            sum[ls(k)] = (sum[ls(k)] * tm[k] + ta[k] * x) % p;
            ta[ls(k)] = (ta[ls(k)] * tm[k] + ta[k]) % p;
            tm[ls(k)] = (tm[ls(k)] * tm[k]) % p;
            sum[rs(k)] = (sum[rs(k)] * tm[k] + ta[k] * y) % p;
            ta[rs(k)] = (ta[rs(k)] * tm[k] + ta[k]) % p;
            tm[rs(k)] = (tm[rs(k)] * tm[k]) % p;
            ta[k] = 0;
            tm[k] = 1;
        }
    }

    void pushup(ll k) {
        sum[k] = (sum[ls(k)] + sum[rs(k)]) % p;
    }

    // 区间修改
    /**
     * @brief 
     * 
     * @param a 区间下界
     * @param b 区间上界
     * @param k 当前线段树结点编号
     * @param l 当前线段树结点左
     * @param r 当前线段树结点右
     * @param x 需要加的数
     */
    void add(ll a, ll b, ll k, ll l, ll r, ll x) {
        if (a <= l && r <= b) {
            sum[k] = (sum[k] + (r - l + 1) * x) % p;
            ta[k] = (ta[k] + x) % p;
            return;
        }
        ll m = (l + r) >> 1;
        pushdown(k, m - l + 1, r - m);
        if (a <= m) add(a, b, ls(k), l, m, x);
        if (b > m) add(a, b, rs(k), m + 1, r, x);
        pushup(k);
    }

    // 区间数乘
    /**
     * @brief 
     * 
     * @param a 区间下界
     * @param b 区间上界
     * @param k 当前线段树结点编号
     * @param l 当前线段树结点左
     * @param r 当前线段树结点右
     * @param x 需要乘的数
     */
    void mlt(ll a, ll b, ll k, ll l, ll r, ll x) {
        if (a <= l && r <= b) {
            sum[k] = (sum[k] * x) % p;
            tm[k] = (tm[k] * x) % p;
            ta[k] = (ta[k] * x) % p;
            return;
        }
        ll m = (l + r) >> 1;
        pushdown(k, m - l + 1, r - m);
        if (a <= m) mlt(a, b, ls(k), l, m, x);
        if (b > m) mlt(a, b, rs(k), m + 1, r, x);
        pushup(k);
    }

    // 区间查询
    /**
     * @brief 
     * 
     * @param a 查询区间下界
     * @param b 查询区间上界
     * @param k 当前线段树结点编号
     * @param l 当前线段树结点左
     * @param r 当前线段树结点右
     * @return ll 结果
     */
    ll ask(ll a, ll b, ll k, ll l, ll r) {
        if (a <= l && r <= b) {
            return sum[k];
        }
        ll m = (l + r) >> 1;
        ll ans = 0;
        pushdown(k, m - l + 1, r - m);
        if (a <= m) ans = (ans + ask(a, b, ls(k), l, m)) % p;
        if (b > m) ans = (ans + ask(a, b, rs(k), m + 1, r)) % p;
        return ans;
    }

    void solve() {
        // 1 x y k 给x到y乘上k
        // 2 x y k 给x到y加上k
        // 3 x y 查询x到y的和
        ll m;
        fill(tm, tm + 400005, 1);
        cin >> n >> m >> p;
        for (ll i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            add(i + 1, i + 1, 1, 1, n, tmp);
        }
        for (ll i = 0; i < m; i++) {
            ll s, x, y, k;
            cin >> s;
            if (s == 1) {
                cin >> x >> y >> k;
                mlt(x, y, 1, 1, n, k);
            }
            if (s == 2) {
                cin >> x >> y >> k;
                add(x, y, 1, 1, n, k);
            }
            if (s == 3) {
                cin >> x >> y;
                cout << ask(x, y, 1, 1, n) << endl;
            }
        }
        return;
    }
}

// kruskal&并查集
typedef pair<int, pair<int, int> > ds;
int par[5005], sz[5005];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (sz[px] > sz[py]) swap(px, py);
    par[px] = py;
    sz[py] += sz[px];
}

void Kruskal() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    priority_queue<ds , vector<ds>, greater<ds> > h;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ds d;
        d.first = z;
        d.second.first = x;
        d.second.second = y;
        h.push(d);
    }
    for (int i = 1; i < n; i++) {
        if (h.size() == 0) break;
        ds d = h.top();
        h.pop();
        while (find(d.second.first) == find(d.second.second) && h.size() != 0) {
            d = h.top();
            h.pop();
        }
        merge(d.second.first, d.second.second);
        ans += d.first;
    }
    for (int i = 1; i <= n; i++) {
        if (sz[i] == n) {
            cout << ans;
            return;
        }
    }
    cout << "orz";
    return;
}

// Dijskra
bool vis[1000005];
ll dis[1000005];
typedef struct _Node {
    vector<pair<ll, ll> > to_where; // where, weight
} Node;
Node node[1000005];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q; 

void Dijskra() {
    int n, m, s;
    cin >> n >> m >> s;
    fill(dis, dis + n + 10, INT_MAX);

    for (int i = 0; i < m; i++) {
        int nd;
        cin >> nd;
        int where, value;
        cin >> where >> value;
        node[nd].to_where.push_back(make_pair(where, value));
    }
    vis[s] = true;
    dis[s] = 0;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        for (auto j : node[curr].to_where) {
            if (!vis[j.first] && dis[curr] + j.second < dis[j.first]) {
                dis[j.first] = dis[curr] + j.second;
                q.push(make_pair(dis[j.first], j.first));
            }
        }
        pair<ll, ll> pr = q.top();
        while (vis[pr.second]) {q.pop(); pr = q.top();}
        vis[pr.second] = true;
        // dis[pr.second] = pr.first;
        curr = pr.second;
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << ' ';
    }
    return;
}

// Floyd
void Floyd() {
    ll d[MAXN][MAXN];
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return;
}

// 查找因数
vector<ll> fcts;
void fndf(ll x) {
    for (ll i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            fcts.push_back(i);
            if (i != x / i)
                fcts.push_back(x / i);
        }
}

// 素因数分解
vector<ll> pfcts;
void fndpf(ll x) {
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            fcts.push_back(i), x /= i, --i;
    if (x != 1) pfcts.push_back(x);
    return;
}

// Eratosthenes 筛
bool chk[MAXN]; // 合数为 true
void fillPrime(int rge) {
for (int i = 2; i * i <= rge; ++i)
    if (!chk[i])
        for (int j = i; j <= rge / i; ++j)
            chk[i * j] = true;
}

// gcd
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// lcm
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// 求解ax+by=c的x,y
// 特殊：b=0
// 一般：
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) { x = 1; y = 0; return a;}
    ll d = exgcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}

// Euler函数
// Euler 函数 φ(n) 是定义在 N+ 上的函数, 在正整数 n 处的值为 1, 2, · · · , n
// 中与 n 互素的数的个数.
int phi[MAXN];
vector<int> ps;
void Euler(int rge) {
    phi[1] = 1;
    for (int i = 2; i <= rge; i++) {
        if (phi[i] == 0)
            phi[i] = i - 1, ps.push_back(i);
        for (int j = 0; j < ps.size()
                    && ps[j] <= rge / i; j++)
            if (i % ps[j])
                phi[i * ps[j]] = phi[i] * (ps[j] - 1);
            else {
                phi[i * ps[j]] = phi[i] * ps[j]; break;
            }
    }
    return;
}

// Hash
namespace Hash {
    const int mod = p;
    void _hash() {
        int h = 998244353,b = 19260817;
        char s[MAXN];
        int hash[MAXN],pow_b[MAXN] = {1};
        for(int i=1;i<=n;i++){
            pow_b[i] = 1ll*pow_b[i-1]*b%h;
            hash[i] = (1ll*hash[i-1]*b+s[i]-'a'+1)%h;
        }
    }
    int get_hash(int r,int l){
        // return (hash[r]+mod-1ll*pow_b[r-l+1]*hash[l-1]%mod)%mod;
        return 0;
    }
}

// KMP
char s[MAXN];
int fail[MAXN];
bool search(char *str) {
    for (int i = 0, j = 0; str[i]; i++) {
        while (j && str[i] != s[j])j = fail[j - 1];
        if (str[i] == s[j] && !s[++j]) return true;
    }
    return false;
}

void make_fail()
{
    for (int i = 1, j = 0; s[i]; i++) {
        while (j && s[i] != s[j])j = fail[j - 1];
        if (s[i] == s[j])fail[i] = ++j;
        else fail[i] = 0;
    }
}

// Trie树
#define LETTER 26
struct Trie{
    int num;
    int next[LETTER];
} trie[500001];
int cnt;

void init() {
    cnt = 0;
    memset(trie, 0, sizeof(Trie));
}

void insert(char *s) {
    int cur = 0;
    for (int i = 0; s[i]; i++) {
        int pos = trie[cur].next[s[i]-'a'];
        if (!pos){
            pos = ++cnt;
            memset(trie[cnt], 0, sizeof(Trie));
        }
        cur = pos;
    }
    trie[cur].num++;
}

// Trie树的查找：
int search(char *s)
{
  int cur = 0;
  for (int i = 0; s[i]; i++) {
    cur = trie[cur].next[convert(s[i])];
    if (!cur)return -1;
  }
  return trie[cur].num;
}

// Trie树的遍历：
char temp[1001];
void dfs(int i, int h)
{
    if (trie[i].num){
        temp[h] = 0;
        printf("%s %d\n", temp, trie[i].num);
    }
    for (int j = 0; j < LETTER; j++) {
        if (trie[i].next[j]) {
            temp[h] = j+'a';
            dfs(trie[i].next[j], h + 1);
        }
    }
}

int main() {
    // merge()
    // a[0] = 7;
    // a[1] = 5;
    // a[2] = 9;
    // a[3] = 10;
    // a[4] = 1;
    // a[5] = 2;
    // a[6] = 8;
    // a[7] = 3;
    // a[8] = 4;
    // a[9] = 6;
    // merge(0, 10);
    // for (int i = 0; i < 10; i++) {cout << a[i] << ' ';}
}