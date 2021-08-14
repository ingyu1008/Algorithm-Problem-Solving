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

    pll eps; // 분자, 분모
    std::cin >> eps.first >> eps.second;

    pll axb; // ax + b
    std::cin >> axb.first >> axb.second;

    ll x0;
    std::cin >> x0;

    std::cout << axb.first * x0 + axb.second << "\n";

    if (axb.first == 0)
    {
        std::cout << "0 0\n";
    }
    else
    {
        ll x = gcd(std::abs(axb.first), eps.first);
        eps.first /= x;
        eps.second *= (std::abs(axb.first) / x);
        if (eps.second > 1e8)
        {
            std::cout << "0 0\n";
        }
        else
        {
            std::cout << eps.first << " " << eps.second << "\n";
        }
    }

    return 0;
}
