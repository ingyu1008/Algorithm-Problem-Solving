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

ll par[101010];
ll dp[101010];

ll find(ll a)
{
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(ll a, ll b)
{
    a = find(a);
    b = find(b);

    if (a < b)
    {
        par[a] = b;
        dp[b] += dp[a];
    }
    else if (a > b)
    {
        par[b] = a;
        dp[a] += dp[b];
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1; i < 101010; i++)
    {
        par[i] = i;
        dp[i] = 1;
    }

    std::priority_queue<std::pair<ll, std::pair<ll, ll>>> pq;

    for (int i = 1, x, y, z; i < N; i++)
    {
        std::cin >> x >> y >> z;
        pq.push({z, {x, y}});
    }

    ll ans = 0;

    while (!pq.empty())
    {
        ll weight = pq.top().first;
        ll a = pq.top().second.first;
        ll b = pq.top().second.second;
        pq.pop();

        ll aa = find(a);
        ll bb = find(b);

        if (aa != bb)
        {
            ans += (dp[aa] * dp[bb]) * weight;
            uni(a, b);
        }
    }

    std::cout << ans << "\n";

    return 0;
}
