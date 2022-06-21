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

int rook(int x, int y)
{
    return x ^ y;
}

int bishop(int x, int y)
{
    return std::min(x, y);
}

int knight(int x, int y)
{
    if (x == y)
    {
        return ((x % 3) == 2 && (y % 3) == 2);
    }
    int z = std::min(x, y) % 3;
    if (z == 0)
        return 0;
    if (z == 2 && std::abs(x - y) > 1)
        return 2;
    return 1;
}

int king(int x, int y)
{
    if (!(x & 1) && !(y & 1))
        return 0;
    if ((x & 1) && (y & 1))
        return 2;
    if (std::min(x, y) & 1)
        return 3;
    return 1;
}

int gungjun(int x, int y)
{
    return 3 * ((x / 3) ^ (y / 3)) + (x + y) % 3;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int res = 0;

    while (N--)
    {
        int x, y;
        std::string s;
        std::cin >> x >> y >> s;

        if (s == "R")
        {
            res ^= rook(x, y);
        }
        if (s == "B")
        {
            res ^= bishop(x, y);
        }
        if (s == "K")
        {
            res ^= king(x, y);
        }
        if (s == "N")
        {
            res ^= knight(x, y);
        }
        if (s == "P")
        {
            res ^= gungjun(x, y);
        }
    }

    std::cout << ((res) ? "koosaga" : "cubelover") << "\n";

    return 0;
}
