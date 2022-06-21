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
int N, D;

std::vector<ll> T(101010), V(101010);
ll ans = 0;

ll C(ll i, ll j) {
    return (j - i) * T[j] + V[i];
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) return;

    int m = (l + r) / 2;
    ll opt = -1;
    int optidx = -1;

    for (int k = std::max(optl, m - D); k <= std::min(m, optr); k++) {

        ll cur = C(k, m);
        if (cur > opt) {
            opt = cur;
            optidx = k;
        }
    }

    ans = std::max(ans, opt);

    solve(l, m - 1, optl, optidx);
    solve(m + 1, r, optidx, optr);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> D;

    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> V[i];
    }

    solve(0, N - 1, 0, N - 1);

    std::cout << ans << std::endl;

    return 0;
}
