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

ll dp[101][101];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    std::vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++)
        std::cin >> v[i];

    for (int i = 1; i <= N; i++)
        dp[i][1] = std::max(dp[i - 1][1] + v[i], v[i]);

    for (int i = 2; i <= M; i++)
        for (int j = 2 * i - 2; j <= N; j++) {
            if (j != 2 * i - 2) dp[j][i] = dp[j - 1][i] + v[j];
            for (int k = i - 1; k < j - 1; k++) {
                dp[j][i] = std::max(dp[j][i], dp[k][i - 1] + v[j]);
            }
        }

    std::cout << dp[N][M] << std::endl;

    return 0;
}
