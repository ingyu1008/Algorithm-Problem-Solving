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

    std::string s;
    std::cin >> s;

    int o = 0, x = 0, q = 0;

    for (int i = 0; i < s.size(); i++)
    {
        o += s[i] == 'o';
        x += s[i] == 'x';
        q += s[i] == '?';
    }

    if (o > 4)
    {
        std::cout << 0;
    }
    else if (o == 4)
    {
        std::cout << 24;
    }
    else if (o == 3)
    {
        std::cout << 24 * q + 6 * 3 * 2;
    }
    else if (o == 2)
    {
        std::cout << 12 * q * (q - 1) + 6 * 3 * 2 * q + (6 + 4 * 2);
    }
    else if (o == 1)
    {
        std::cout << 4 * q * (q - 1) * (q - 2) + 6 * 3 * 2 * q * (q - 1) / 2 + (6 + 4 * 2) * q + 1;
    }
    else
    {
        std::cout << q * (q - 1) * (q - 2) * (q - 3) + 6 * 3 * 2 * q * (q - 1) * (q - 2) / 6 + (6 + 4 * 2) * q * (q - 1) / 2 + q;
    }

    return 0;
}
