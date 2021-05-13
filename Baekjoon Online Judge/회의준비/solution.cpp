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

    int N, M;
    std::cin >> N >> M;

    std::vector<pll> v[N + 1];
    ll dist[101][101];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dist[i][j] = 1e18;
        }
        dist[i][i] = 0;
    }

    for (int i = 0, a, b; i < M; i++)
    {
        std::cin >> a >> b;
        dist[a][b] = std::min(dist[a][b], 1LL);
        dist[b][a] = std::min(dist[b][a], 1LL);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    std::set<int> ans;

    for (int i = 1; i <= N; i++)
    {
        int mnidx = 0;
        ll mn = 1e18;
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] == 1e18)
                continue;
            ll mxdist = 0;
            for (int k = 1; k <= N; k++)
            {
                if (dist[j][k] == 1e18)
                    continue;
                mxdist = std::max(mxdist, dist[j][k]);
            }
            if (mn > mxdist)
            {
                mn = mxdist;
                mnidx = j;
            }
        }
        ans.insert(mnidx);
    }

    std::cout << ans.size() << "\n";
    for (auto x : ans)
    {
        std::cout << x << "\n";
    }

    return 0;
}
