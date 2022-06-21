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
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
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

ll dp[200][20000];

int N, M;
ll solve(int now, int bitmask)
{
    if (dp[now][bitmask] >= 0)
        return dp[now][bitmask];
    if (now == N * M)
        return (bitmask == 0);
    if(now > N*M) return 0;
    if (bitmask & 1)
    {
        return dp[now][bitmask] = solve(now + 1, bitmask >> 1);
    }
    ll res = solve(now + 1, (bitmask >> 1) + (1 << M - 1));
    if ((bitmask & 2) == 0 && now % M != M - 1)
    {
        res += solve(now + 2, (bitmask >> 2));
    }
    return dp[now][bitmask] = res;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    while(true){
        for (int i = 0; i < 200; i++)
        {
            for (int j = 0; j < 20000; j++)
            {
                dp[i][j] = -1;
            }
        }
    
        std::cin >> N >> M;
        if(N == 0 && M == 0)break;
        std::cout << solve(0, 0) << "\n";
    }
    return 0;
}