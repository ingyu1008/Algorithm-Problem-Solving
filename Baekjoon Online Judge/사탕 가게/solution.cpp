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
    double x;
    std::cin >> N >> x;
    M = x * 100 + 0.5;

    while (true)
    {
        if (N == 0 && M == 0)
            break;
        std::vector<ll> c(N), p(N);
        std::vector<ll> dp(10101);

        for (int i = 0; i < N; i++)
        {
            std::cin >> c[i] >> x;
            p[i] = x * 100 + 0.5;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = p[i]; j <= M; j++)
            {
                dp[j] = std::max(dp[j], dp[j - p[i]] + c[i]);
            }
        }

        std::cout << dp[M] << "\n";

        std::cin >> N >> x;
        M = x * 100 + 0.5;
    }
}