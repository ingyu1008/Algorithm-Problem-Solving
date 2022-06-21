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
std::vector<ll> v(5050);
std::vector<ll> dp_before(5050), dp_after(5050);

ll cost[5050][5050];

void initCost() {
    for (int i = 0; i < 5050; i++) {
        cost[i][i] = v[i];
        for (int j = i+1; j < 5050; j++) {
            cost[i][j] = cost[i][j-1] | v[j];
        }
    }
}

ll C(int i, int j) {
    return cost[i][j];
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) return;

    int m = (l + r) / 2;
    ll opt = -1;
    int optidx = -1;

    for (int k = optl; k <= std::min(m, optr); k++) {

        ll cur = ((k > 0) ? dp_before[k - 1] : 0) + C(k, m);
        // std::cout << "k : " << k << " cur : " << cur << std::endl;
        if (cur > opt) {
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

    int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < N; i++)
        std::cin >> v[i];

    initCost();

    for (int i = 0; i < N; i++) {
        dp_before[i] = C(0, i);
    }

    for (int i = 1; i < K; i++) {
        solve(i, N - 1, i, N - 1);
        dp_before = dp_after;
    }

    std::cout << dp_before[N - 1] << '\n';

    return 0;
}
