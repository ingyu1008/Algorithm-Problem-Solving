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

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M, W;
        std::cin >> N >> M >> W;

        std::vector<pll> v[N + 1];
        std::vector<ll> dist(N + 1, 1e18);
        for (int i = 0, x, y, z; i < M; i++)
        {
            std::cin >> x >> y >> z;
            v[x].push_back({y, z});
            v[y].push_back({x, z});
        }
        for (int i = 0, x, y, z; i < W; i++)
        {
            std::cin >> x >> y >> z;
            v[x].push_back({y, -z});
        }

        bool negCycle = false;

        dist[1] = 0;

        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
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
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}
