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

ll dp[8];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == 'c')
        {
            dp[0]++;
        }
        else if (s[i] == 'h')
        {
            dp[1] = (dp[1] + dp[0]) % mod;
        }
        else if (s[i] == 'o')
        {
            dp[2] = (dp[2] + dp[1]) % mod;
        }
        else if (s[i] == 'k')
        {
            dp[3] = (dp[3] + dp[2]) % mod;
        }
        else if (s[i] == 'u')
        {
            dp[4] = (dp[4] + dp[3]) % mod;
        }
        else if (s[i] == 'd')
        {
            dp[5] = (dp[5] + dp[4]) % mod;
        }
        else if (s[i] == 'a')
        {
            dp[6] = (dp[6] + dp[5]) % mod;
        }
        else if (s[i] == 'i')
        {
            dp[7] = (dp[7] + dp[6]) % mod;
        }
    }

    std::cout << dp[7];

    return 0;
}
