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
#include <queue>

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

std::vector<std::pair<int, int>> v[1010], rev[1010];

int dist[1010], revdist[1010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M, X;
    std::cin >> N >> M >> X;

    for (int i = 0, x, y, z; i < M; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
        rev[y].push_back({x, z});
    }

    std::fill_n(dist, 1010, 1e9 + 7);
    std::fill_n(revdist, 1010, 1e9 + 7);

    std::priority_queue<std::pair<int, int>> pq, revpq;

    pq.push({0, X});
    dist[X] = 0;

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

    revpq.push({0, X});
    revdist[X] = 0;

    while (!revpq.empty())
    {
        int cost = -revpq.top().first;
        int node = revpq.top().second;
        revpq.pop();

        if (revdist[node] < cost)
            continue;

        for (auto p : rev[node])
        {
            if (revdist[p.first] > cost + p.second)
            {
                revdist[p.first] = cost + p.second;
                revpq.push({-revdist[p.first], p.first});
            }
        }
    }

    int mx = 0;
    for(int i = 1; i <= N; i++){
        mx = std::max(mx, dist[i] + revdist[i]);
    }

    std::cout << mx << "\n";

    return 0;
}
