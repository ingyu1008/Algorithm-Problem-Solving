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
#include <queue>
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

int dist[20202];
std::vector<std::pair<int, int>> v[20202];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int V, E;
    std::cin >> V >> E;

    int K;
    std::cin >> K;
    std::fill_n(dist, 20202, 1e9 + 7);

    for (int i = 0, x, y, z; i < E; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
    }

    dist[K] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, K});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (auto p : v[node])
        {
            if (dist[p.first] > cost + p.second)
            {
                dist[p.first] = cost + p.second;
                pq.push({-dist[p.first], p.first});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == 1e9 + 7)
        {
            std::cout << "INF\n";
        }
        else
        {
            std::cout << dist[i] << "\n";
        }
    }

    return 0;
}
