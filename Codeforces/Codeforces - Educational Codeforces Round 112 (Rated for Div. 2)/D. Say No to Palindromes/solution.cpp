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

int dp[6][202020];
int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    int N, M;
    std::string s;

    std::cin >> N >> M >> s;

    for (int i = 0; i < N; i++)
    {
        if (s[i] != ('a' + (i % 3)))
        {
            //abc
            dp[0][i + 1]++;
        }
        if (s[i] != ('a' + ((i + 1) % 3)))
        {
            //bca
            dp[1][i + 1]++;
        }
        if (s[i] != ('a' + ((i + 2) % 3)))
        {
            //cab
            dp[2][i + 1]++;
        }
        if (s[i] != ('c' - ((i + 2) % 3)))
        {
            //acb
            dp[3][i + 1]++;
        }
        if (s[i] != ('c' - (i % 3)))
        {
            //cba
            dp[4][i + 1]++;
        }
        if (s[i] != ('c' - ((i + 1) % 3)))
        {
            //bac
            dp[5][i + 1]++;
        }

        for (int j = 0; j < 6; j++)
        {
            dp[j][i + 1] += dp[j][i];
        }
    }

    int l, r;
    while (M--)
    {
        std::cin >> l >> r;
        int mn = N;
        for (int i = 0; i < 6; i++)
        {
            mn = std::min(mn, dp[i][r] - dp[i][l - 1]);
        }
        std::cout << mn << "\n";
    }

    return 0;
}
