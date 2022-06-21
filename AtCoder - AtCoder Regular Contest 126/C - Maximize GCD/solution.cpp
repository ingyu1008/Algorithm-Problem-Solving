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

    ll N, K;
    std::cin >> N >> K;
    std::vector<ll> v(N);
    ll mx = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
        mx = std::max(mx, v[i]);
    }

    ll ans = 1;
    ll lo = 1;
    ll hi = 1e13;
    while (lo <= hi)
    {
        ll m = (lo + hi) >> 1;
        ll cnt = N * (m - 1);
        if (cnt <= K)
        {
            ans = std::max(ans, m);
            lo = m + 1;
        }
        else
        {
            hi = m - 1;
        }
    }
    ll m = ans;
    ll cntt = 0;
    while (m <= mx)
    {
        ll cnt = 0;
        m++;
        for (int i = 0; i < N; i++)
        {
            cnt += (m - (v[i] % m)) % m;
        }
        if (cnt <= K)
        {
            ans = std::max(ans, m);
            cntt = cnt;
        }
    }

    std::cout << ans + (K - cntt)/N << "\n";

    return 0;
}
