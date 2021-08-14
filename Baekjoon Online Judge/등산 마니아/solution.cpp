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

ll sz[1 << 19];
ll sz2[1 << 19];
std::vector<int> v[1 << 19];

ll dfs(int node, int par)
{
    sz[node] = 1;

    for (auto x : v[node])
    {
        if (x == par)
            continue;
        sz[node] += dfs(x, node);
    }

    return sz[node];
}

ll dfs2(int node, int par)
{
    sz2[node] = 0;

    for (auto x : v[node])
    {
        if (x == par)
            continue;
        sz2[node] += dfs2(x, node);
        sz2[node] += sz[x];
        sz2[node] += (sz[node] - sz[x]) * sz[x];
    }

    return sz2[node];
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1, a, b; i < N; i++)
    {
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0);
    dfs2(1, 0);

    std::cout << sz2[1] << "\n";

    return 0;
}
