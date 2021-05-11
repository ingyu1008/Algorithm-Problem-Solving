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

std::vector<std::pair<ll, ll>> v[101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> visible(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> visible[i];
    }

    visible[N - 1] = 0;

    std::vector<ll> dist(N, 1e18);

    dist[0] = 0;

    for (int i = 0, x, y, z; i < M; i++)
    {
        std::cin >> x >> y >> z;
        if (visible[y] == 0)
            v[x].push_back({y, z});
        if (visible[x] == 0)
            v[y].push_back({x, z});
    }

    std::priority_queue<std::pair<ll, ll>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        ll cost = -pq.top().first;
        ll node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;

        for (auto p : v[node])
        {
            if(dist[p.first] > cost + p.second){
                dist[p.first] = cost + p.second;
                pq.push({-dist[p.first], p.first});
            }
        }
    }

    if(dist[N-1] == 1e18){
        std::cout << "-1\n";
    } else {
        std::cout << dist[N-1] << "\n";
    }

    return 0;
}
