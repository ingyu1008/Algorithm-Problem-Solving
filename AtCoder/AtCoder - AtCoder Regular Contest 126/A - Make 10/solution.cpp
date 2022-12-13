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

    int T;
    std::cin >> T;
    while (T--)
    {
        ll a, b, c;
        std::cin >> a >> b >> c;
        b /= 2;
        ll bc = std::min(b, c);
        c -= bc;
        b -= bc;
        ll ab = std::min(a / 2, b);
        a -= ab * 2;
        b -= ab;
        ll ac2 = std::min(a, c / 2);
        a -= ac2;
        c -= ac2 * 2;
        ll a3c = std::min(a / 3, c);
        a -= a3c * 3;
        c -= a3c;
        std::cout << bc + ab + ac2 + a3c +  a / 5 << "\n";
    }

    return 0;
}
