/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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

std::vector<ll> S, L, O;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    // Si * max(1, x-Li)

    ll N, G, K;
    std::cin >> N >> G >> K;

    for (int i = 0; i < N; i++) {
        ll Si, Li, Oi;
        std::cin >> Si >> Li >> Oi;

        S.push_back(Si);
        L.push_back(Li);
        O.push_back(Oi);
    }

    ll lo = 0;
    ll hi = 1e10;

    ll ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll val = 0;
        std::vector<ll> v;
        for (int i = 0; i < N; i++) {
            ll Si = S[i];
            ll Li = L[i];
            ll Oi = O[i];
            ll g = Si * std::max(1LL, mid - Li);
            val += g;
            if (Oi == 1) {
                v.push_back(g);
            }
        }

        std::sort(v.rbegin(), v.rend());

        for (int i = 0; i < std::min((ll)v.size(), K); i++) {
            val -= v[i];
        }

        if (val > G) {
            hi = mid - 1;
        } else {
            ans = std::max(ans, mid);
            lo = mid + 1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}