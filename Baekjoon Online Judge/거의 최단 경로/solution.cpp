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

vpii v[500], rv[500];
bool removed[500][500];
std::vector<ll> dist(500, 1e9 + 7);
std::priority_queue<pll> pq;
std::queue<int> q;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M, S, D;
    while (1)
    {
        std::cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        for (int i = 0; i < 500; i++)
        {
            v[i].clear();
            rv[i].clear();
            for (int j = 0; j < 500; j++)
            {
                removed[i][j] = false;
            }
        }
        std::cin >> S >> D;

        for (int i = 0, x, y, z; i < M; i++)
        {
            std::cin >> x >> y >> z;
            v[x].push_back({y, z});
            rv[y].push_back({x, z});
        }

        std::fill(dist.begin(), dist.begin() + N, 1e9 + 7);
        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            ll cost = -pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            if (cost > dist[node])
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

        bool checked[500];
        std::fill_n(checked, 500, false);

        q.push(D);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto p : rv[node])
            {
                if (dist[p.first] + p.second == dist[node])
                {
                    removed[p.first][node] = true;
                    if (!checked[p.first])
                        checked[p.first] = true, q.push(p.first);
                }
            }
        }

        std::fill(dist.begin(), dist.begin() + N, 1e9 + 7);
        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            ll cost = -pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            if (cost > dist[node])
                continue;

            for (auto p : v[node])
            {
                if (!removed[node][p.first] && dist[p.first] > cost + p.second)
                {
                    dist[p.first] = cost + p.second;
                    pq.push({-dist[p.first], p.first});
                }
            }
        }

        if (dist[D] == 1e9 + 7)
        {
            std::cout << "-1\n";
        }
        else
        {
            std::cout << dist[D] << "\n";
        }
    }

    return 0;
}
