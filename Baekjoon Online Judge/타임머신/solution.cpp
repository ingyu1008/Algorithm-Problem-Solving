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
std::vector<pll> v[505];
std::vector<ll> dist(505, 3e18);

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    dist[1] = 0;

    for (int i = 0, x, y, z; i < M; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
    }

    bool negCycle = false;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (dist[j] == 3e18)
                continue;
            for (auto p : v[j])
            {
                if (dist[p.first] > dist[j] + p.second)
                {
                    dist[p.first] = dist[j] + p.second;
                }
            }
        }
    }

    for (int j = 1; j <= N; j++)
    {
        if (dist[j] == 3e18)
            continue;
        for (auto p : v[j])
        {
            if (dist[p.first] > dist[j] + p.second)
            {
                negCycle = true;
            }
        }
    }

    if (negCycle)
    {
        std::cout << "-1\n";
    }
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == 3e18)
                std::cout << "-1\n";
            else
                std::cout << dist[i] << "\n";
        }
    }

    return 0;
}
