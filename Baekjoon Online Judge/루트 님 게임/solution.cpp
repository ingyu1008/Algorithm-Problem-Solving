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

    int N;
    std::cin >> N;
    std::vector<ll> v(N);

    ll res = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
        if (v[i] < 4)
            res ^= 0;
        else if (v[i] < 16)
            res ^= 1;
        else if (v[i] < 82)
            res ^= 2;
        else if (v[i] < 6724)
            res ^= 0;
        else if (v[i] < 50626)
            res ^= 3;
        else if (v[i] < 2562991876LL)
            res ^= 1;
        else
            res ^= 2;
    }

    std::cout << ((res) ? "koosaga" : "cubelover") << "\n";

    return 0;
}
