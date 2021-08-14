/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<pii> vpii;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
        b = (b * a) % mod;
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        a ^= b ^= a ^= b;
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

/********************************************************************
						End Of Template
********************************************************************/
int N;
std::vector<std::pair<pii, int>> v[1 << 17];

struct Node
{
    ll sz, dep, par, top, in, out, value;
} info[1 << 17];

ll tree[1 << 20];

void update(int node, int l, int r, int x, int c)
{
    if (l > x || r < x)
        return;
    if (l == r)
    {
        tree[node] = c;
        return;
    }

    int m = (l + r) >> 1;
    update(node * 2, l, m, x, c);
    update(node * 2 + 1, m + 1, r, x, c);
    tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
}

ll query(int node, int l, int r, int s, int e)
{
    s++;
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];

    int m = (l + r) >> 1;
    s--;
    return std::max(query(node * 2, l, m, s, e), query(node * 2 + 1, m + 1, r, s, e));
}

void dfs(int x = 1)
{
    info[x].sz = 1;
    for (auto &y : v[x])
    {
        if (info[y.first.first].sz > 0)
            continue;
        info[y.first.first].dep = info[x].dep + 1;
        info[y.first.first].par = x;
        dfs(y.first.first);
        info[x].sz += info[y.first.first].sz;

        if (info[y.first.first].sz > info[v[x][0].first.first].sz)
            std::swap(y, v[x][0]);
    }
}

int w;
void dfs2(int x = 1)
{
    info[x].in = ++w;
    update(1, 1, N, w, info[x].value);
    for (auto y : v[x])
    {
        if (y.first.first == 1 || info[y.first.first].in > 0)
            continue;
        info[y.first.first].top = (y.first.first == v[x][0].first.first) ? info[x].top : y.first.first;
        info[y.first.first].value = y.first.second;
        dfs2(y.first.first);
    }
    info[x].out = w;
}

vpii vv(1 << 17);

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 1, x, y, z; i < N; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({{y, z}, i});
        v[y].push_back({{x, z}, i});
        vv[i] = {x, y};
    }

    dfs();
    dfs2();

    int M;
    std::cin >> M;
    int x, y, z;
    while (M--)
    {
        std::cin >> x >> y >> z;
        if (x == 1)
        {
            x = (info[vv[y].first].dep > info[vv[y].second].dep) ? vv[y].first : vv[y].second;
            update(1, 1, N, info[x].in, z);
        }
        else
        {
            ll mx = 0;
            while (info[y].top != info[z].top)
            {
                if (info[y].dep < info[z].dep)
                    std::swap(y, z);
                mx = std::max(mx, query(1, 1, N, info[info[y].top].in, info[y].in));
                y = info[info[y].top].par;
            }
            if (info[y].dep > info[z].dep)
                std::swap(y, z);
            mx = std::max(mx, query(1, 1, N, info[y].in, info[z].in));
            std::cout << mx << "\n";
        }
    }

    return 0;
}
