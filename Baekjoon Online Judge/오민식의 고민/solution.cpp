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

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, S, E, M;
    std::cin >> N >> S >> E >> M;

    std::vector<std::pair<ll, std::pair<ll, ll>>> v;

    for (int i = 0, x, y, z; i < M; i++)
    {
        std::cin >> x >> y >> z;
        v.push_back({z, {x, y}});
    }

    std::vector<ll> earn(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> earn[i];
        earn[i] *= -1;
    }

    std::vector<ll> dist1(N, 1e18);
    std::vector<ll> dist2(N, 1e18);
    dist1[S] = earn[S];
    dist2[E] = earn[E];

    bool cycle = false;

    for (int i = 0; i < N - 1; i++)
    {
        for (auto p : v)
        {
            ll cost = p.first;
            ll from = p.second.first;
            ll to = p.second.second;

            if (dist1[to] > dist1[from] + cost + earn[to])
            {
                dist1[to] = dist1[from] + cost + earn[to];
            }
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (auto p : v)
        {
            ll cost = p.first;
            ll from = p.second.second;
            ll to = p.second.first;

            if (dist2[to] > dist2[from] + cost + earn[to])
            {
                dist2[to] = dist2[from] + cost + earn[to];
            }
        }
    }

    for (auto p : v)
    {
        ll cost = p.first;
        ll from = p.second.first;
        ll to = p.second.second;

        if (dist2[from] != 1e18 && dist1[from] != 1e18 && dist1[to] > dist1[from] + cost + earn[to])
        {
            cycle = true;
        }
    }

    if (dist1[E] >= 1e18)
        std::cout << "gg\n";
    else if (cycle)
        std::cout << "Gee\n";
    else
        std::cout << -dist1[E]<< "\n";

    return 0;
}
