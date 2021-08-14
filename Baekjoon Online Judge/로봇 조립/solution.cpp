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

int par[1010101];
int dp[1010101];

int find(int a)
{
    if (a == par[a])
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a < b)
    {
        par[a] = b;
        dp[b] += dp[a];
    }
    else if(a > b)
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

    for (int i = 1; i < 1010101; i++)
    {
        par[i] = i;
        dp[i] = 1;
    }
    std::string s;
    int a, b;
    while (N--)
    {
        std::cin >> s;
        if(s == "I"){
            std::cin >> a >> b;
            uni(a,b);
        } else {
            std::cin >> a;
            std::cout << dp[find(a)] << "\n";
        }
    }

    return 0;
}
