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

ll mod = 998244353;

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

ll fact[202020];

ll factmod(ll n, ll mod)
{
    if (n == 0)
        return fact[0] = 1;
    if (fact[n] >= 0)
        return fact[n];

    return fact[n] = (factmod(n - 1, mod) * n) % mod;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::fill_n(fact, 202020, -1);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        std::vector<ll> v(N);
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
        }
        std::sort(v.rbegin(), v.rend());

        ll res = factmod(N, mod);

        if (v[0] == v[1])
        {
            std::cout << res << "\n"; // N!
        }
        else if (v[0] == v[1] + 1)
        {
            int x = 1;
            while (x + 1 < N && v[x + 1] == v[x])
            {
                x++;
            }
            ll subres = (res * powmod(x + 1, mod - 2))%mod;//1 작은게 모두 왼쪽에 ( x! * (x+2) ~ N)
            std::cout << ((res - subres)%mod + mod) % mod << "\n";
        } else {
            std::cout << "0\n";
        }
    }

    return 0;
}
