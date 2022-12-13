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

std::pair<int, std::pair<int, std::pair<int, int>>> dp[101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int R, N;
    std::cin >> R >> N;

    dp[0] = {0, {0, {1, 1}}};

    int ans = 0;

    for (int i = 1, t, x, y; i <= N; i++)
    {
        std::cin >> t >> x >> y;
        if (i >= 1001)
        {
            dp[i - 1000].first = std::max(dp[i - 1000].first, dp[i - 1001].first);
            dp[i].first = dp[i - 1000].first + 1;
            dp[i].second.first = t;
            dp[i].second.second.first = x;
            dp[i].second.second.second = y;
        }
        for (int j = std::max(0, i - 1000); j < i; j++)
        {
            if (dp[j].first + 1 <= dp[i].first)
                continue;
            int dist = std::abs(dp[j].second.second.first - x) + std::abs(dp[j].second.second.second - y);
            int mx = t - dp[j].second.first;
            if (dist > mx)
                continue;
            dp[i].first = dp[j].first + 1;
            dp[i].second.first = t;
            dp[i].second.second.first = x;
            dp[i].second.second.second = y;
        }
        // std::cout << i << " " << dp[i].first << "\n";
        ans = std::max(ans, dp[i].first);
    }

    std::cout << ans << "\n";

    return 0;
}
