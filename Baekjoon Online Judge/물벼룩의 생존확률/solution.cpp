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

ll dp[2020][2020];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int k, n;
    std::cin >> k >> n;

    for (int i = 1; i <= k + 2 * n; ++i)
        dp[i][0] = 1;

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= k + n; i++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1];
        }
    }

    std::cout << dp[k][n] << "\n";

    return 0;
}
