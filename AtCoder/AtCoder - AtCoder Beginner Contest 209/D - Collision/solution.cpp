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

int par[1 << 17][20];
int dep[1 << 17];
std::vector<int> v[1 << 17];

void dfs(int node = 1, int parent = 1)
{
    if (par[node][0])
        return;
    par[node][0] = parent;
    dep[node] = dep[par[node][0]] + 1;
    for (int i = 1; i < 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }

    for (auto x : v[node])
    {
        if (par[x][0])
            continue;
        dfs(x, node);
    }
}

int lca(int a, int b)
{
    if (dep[a] > dep[b])
        std::swap(a, b);

    int diff = dep[b] - dep[a];
    int k = 0;

    while (diff)
    {
        if (diff & 1)
        {
            b = par[b][k];
        }
        diff >>= 1;
        k++;
    }

    //이제 a b 같은 높이

    if (a == b)
        return a;

    for (k = 19; k >= 0; k--)
    {
        if (par[a][k] != par[b][k])
        {
            a = par[a][k];
            b = par[b][k];
        }
    }
    return par[a][0];
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    for (int i = 0, a, b; i < N - 1; i++)
    {
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs();

    for (int i = 0, c, d; i < Q; i++)
    {
        std::cin >> c >> d;
        int e = lca(c, d);

        int ans = 2 * dep[e] - dep[c] - dep[d];
        if (ans & 1)
        {
            std::cout << "Road\n";
        }
        else
        {
            std::cout << "Town\n";
        }
    }

    return 0;
}
