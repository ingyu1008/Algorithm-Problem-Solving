/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<pii> vpii;
typedef std::vector<pll> vpll;

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

std::vector<std::pair<int, int>> v[101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back({ b, i });
        v[b].push_back({ a, i });
    }

    std::priority_queue<pll, vpll, std::greater<pll>> pq;

    pq.push({ 0, 1 });
    std::vector<ll> dist(N + 1, 1e14);

    while (!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first)
            continue;

        dist[cur.second] = cur.first;

        for (auto& it : v[cur.second])
        {
            if ((it.second >= (cur.first % M)) && (cur.first / M) * M + it.second + 1 < dist[it.first])
                pq.push({ (cur.first / M) * M + it.second + 1, it.first });
            else if ((cur.first / M + 1) * M + it.second + 1 < dist[it.first])
                pq.push({ (cur.first / M + 1) * M + it.second + 1, it.first });
        }
    }

    std::cout << dist[N] << '\n';

    return 0;
}