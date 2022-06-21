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
#include <bitset>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<std::bitset<64>> basis(64);

    for (int i = 0; i < N; ++i)
    {
        ll x;
        std::cin >> x;
        std::bitset<64> y(x);
        
        for (int j = 63; j >= 0; j--) {
            if (y.test(j)) {
                if (basis[j].none()) {
                    basis[j] = y;
                    break;
                } else {
                    y ^= basis[j];
                }
            }
        }
    }

    // Make RREF
    for (int i = 0; i < 64; i++) {
        if (basis[i].none()) {
            continue;
        }
        for (int j = i + 1; j < 64; j++) {
            if (basis[j].test(i)) {
                basis[j] ^= basis[i];
            }
        }
    }

    ll ans = 0;

    for(int i = 0; i < 63; i++){
        ans ^= basis[i].to_ullong();
    }

    std::cout << ans << "\n";

    return 0;
}
