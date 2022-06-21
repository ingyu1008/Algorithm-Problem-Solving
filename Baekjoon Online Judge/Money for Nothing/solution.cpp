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

int M, N;
std::vector<std::pair<ll, ll>> v, vv, w, ww;
ll ans = 0;

void solve(int l, int r, int optl, int optr) {
    if (l > r)return;
    int m = (l + r) / 2;

    ll opt = -9e18;
    int optidx = optl;

    for (int i = optl; i <= optr; i++) {
        ll dx = ww[i].first - vv[m].first;
        ll dy = ww[i].second - vv[m].second;
        ll d = dx * dy;
        if (dx < 0 && dy < 0) d = 0;
        if (d > opt) {
            opt = d;
            optidx = i;
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

    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        ll a, b;
        std::cin >> a >> b;
        v.push_back({ a, b });
    }
    for (int i = 0; i < M; i++) {
        ll a, b;
        std::cin >> a >> b;
        w.push_back({ a, b });
    }

    std::sort(v.begin(), v.end());
    std::sort(w.begin(), w.end(), std::greater<std::pair<ll, ll>>());

    for (int i = 0; i < N; i++) if (i == 0 || vv.back().second > v[i].second) vv.push_back(v[i]);
    for (int i = 0; i < M; i++) if (i == 0 || ww.back().second < w[i].second) ww.push_back(w[i]);
    std::reverse(ww.begin(), ww.end());

    solve(0, vv.size() - 1, 0, ww.size() - 1);

    std::cout << ans << "\n";

    return 0;
}