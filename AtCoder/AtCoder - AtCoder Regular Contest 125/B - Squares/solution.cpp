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

    ll N;
    std::cin >> N;

    ll ans = 0;

    ll k = 1;
    while (true)
    {
        if (k * k > N)
            break;

        // (z+k)^2 - y = z^2

        // (x+k)^2 - x^2 = 2kx + k^2
        // (z+ k)^2 - z^2 = y
        // y = 2kz + k^2 >= k^2

        // y = 2kz + k^2 일때 x값의 후보
        // x = (z + k) 이면 ( z >= 0 )

        ll lo = 0;
        ll hi = N - k;
        ll mx = 0;
        // z 의 최댓값
        while (lo <= hi)
        {
            ll m = (lo + hi) >> 1;

            if (2 * k * m + k * k <= N)
            {
                mx = std::max(mx, m);
                lo = m + 1;
            }
            else
            {
                hi = m - 1;
            }
        }

        ans = (ans + mx + 1) % 998244353;
        k++;
    }

    std::cout << ans << "\n";

    return 0;
}
