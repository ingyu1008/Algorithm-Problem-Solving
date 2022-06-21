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
int L, G;

std::vector<ll> V(8080);
ll ans = 0;

std::vector<ll> dp_before(8080), dp_after(8080);

ll C(ll i, ll j) {
    return (j - i + 1) * (V[j] - V[i - 1]);
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) return;

    int m = (l + r) / 2;
    ll opt = 1e18;
    int optidx = -1;

    for (int k = optl; k <= std::min(m, optr); k++) {

        ll cur = (k ? dp_before[k - 1] : 0) + C(k, m);
        if (cur < opt) {
            opt = cur;
            optidx = k;
        }
    }

    dp_after[m] = opt;

    solve(l, m - 1, optl, optidx);
    solve(m + 1, r, optidx, optr);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> L >> G;

    for (int i = 1; i <= L; i++) {
        std::cin >> V[i];
        V[i] += V[i - 1];
    }

    for (int i = 1; i <= L; i++) {
        dp_before[i] = C(1, i);
    }

    for (int i = 2; i <= G; i++) {
        solve(i, L, i, L);
        dp_before = dp_after;
    }


    std::cout << dp_before[L] << std::endl;

    return 0;
}
