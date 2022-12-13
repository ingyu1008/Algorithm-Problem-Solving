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

std::vector<std::pair<ll, std::pair<ll, ll>>> v;
ll par[101010];
ll sz[101010];

int parent(int idx)
{
    if (idx == par[idx])
        return idx;
    return par[idx] = parent(par[idx]);
}

void uni(int a, int b)
{
    a = parent(a);
    b = parent(b);
    if (a == b)
        return;
    sz[b] += sz[a];
    par[a] = b;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1, a, b, c; i < N; i++)
    {
        std::cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    std::sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        ans += (sz[parent(v[i].second.first)] * sz[parent(v[i].second.second)]) * v[i].first;
        uni(v[i].second.first, v[i].second.second);
    }
    std::cout << ans << "\n";

    return 0;
}
