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

std::vector<std::pair<int, int>> v[303030]; //to, state: state > 0 means it is valid edge
int sz[303030];                             // 도달 가능한 노드의 개수

int dfs(int node = 1, int par = 0)
{
    sz[node] = 1;
    for (auto p : v[node])
    {
        if (p.first == par)
            continue;
        if (p.second > 0)
        {
            sz[node] += dfs(p.first, node);
        }
        else
        {
            dfs(p.first, node);
        }
    }
    return sz[node];
}

void dfs2(int node = 1, int par = 0)
{
    for (auto p : v[node])
    {
        if (p.first == par)
        {
            if (p.second == 1)
            {
                sz[node] += sz[par];
            }
            else if (p.second == 2)
            {
                sz[node] = sz[par];
            }
        }
    }

    for (auto p : v[node])
    {
        if (p.first == par)
            continue;
        dfs2(p.first, node);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1, a, b, x; i < N; i++)
    {
        std::cin >> a >> b >> x;
        if (x == 0)
        {
            v[a].push_back({b, 2});
            v[b].push_back({a, 2});
        }
        else
        {
            v[a].push_back({b, 1});
            v[b].push_back({a, 0});
        }
    }

    dfs();
    dfs2();

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        cnt += sz[i] == N;
    }

    std::cout << cnt << "\n";

    return 0;
}