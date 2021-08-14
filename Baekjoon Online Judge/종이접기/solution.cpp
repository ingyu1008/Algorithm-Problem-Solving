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

int dp[1 << 8][1 << 8];

void init(int K, int x, int y)
{
    for (int i = 0; i < (1 << K); i++)
    {
        for (int j = 0; j < (1 << K); j++)
        {
            dp[i][j] = (((i & 1) << 1) ^ y) + ((j & 1) ^ x);
        }
    }
}

void solve(int K)
{
    int tmp = 0;
    std::string in;
    for (int k = 0; k < 2 * K; k++)
    {
        std::cin >> in;
        if (in == "R" && (tmp & 1) == 0)
            tmp ^= 1;
        else if (in == "L" && (tmp & 1) == 1)
            tmp ^= 1;
        else if (in == "U" && (tmp & 2) == 2)
            tmp ^= 2;
        else if (in == "D" && (tmp & 2) == 0)
            tmp ^= 2;
    }

    // std::cout << tmp << "\n";

    int h;
    std::cin >> h;

    if (tmp == 0)
    {
        if (h == 0)
            init(K, 0, 0);
        else if (h == 1)
            init(K, 1, 0);
        else if (h == 2)
            init(K, 0, 2);
        else
            init(K, 1, 2);
    }
    else if (tmp == 1)
    {
        if (h == 0)
            init(K, 1, 0);
        else if (h == 1)
            init(K, 0, 0);
        else if (h == 2)
            init(K, 1, 2);
        else
            init(K, 0, 2);
    }
    else if (tmp == 2)
    {
        if (h == 0)
            init(K, 0, 2);
        else if (h == 1)
            init(K, 1, 2);
        else if (h == 2)
            init(K, 0, 0);
        else
            init(K, 1, 0);
    }
    else
    {
        if (h == 0)
            init(K, 1, 2);
        else if (h == 1)
            init(K, 0, 2);
        else if (h == 2)
            init(K, 1, 0);
        else
            init(K, 0, 0);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int K;
    std::cin >> K;

    solve(K);

    for (int i = 0; i < (1 << K); i++)
    {
        for (int j = 0; j < (1 << K); j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
