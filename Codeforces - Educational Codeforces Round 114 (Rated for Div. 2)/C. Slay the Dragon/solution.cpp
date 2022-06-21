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

    int N;
    std::cin >> N;
    std::vector<ll> hero(N);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> hero[i];
        sum += hero[i];
    }
    std::sort(hero.begin(), hero.end());

    int M;
    std::cin >> M;
    while (M--)
    {
        ll x, y;
        std::cin >> x >> y;
        auto it = std::upper_bound(hero.begin(), hero.end(), x - 1);

        ll lo = 0;
        ll hi = 2e18;
        ll ans = 2e18;
        while (lo <= hi)
        {
            ll m = (lo + hi) >> 1;
            //find weakest that can defeat dragon;
            bool case1 = false;
            if (hero[N - 1] >= x)
            {
                ll a = *it;
                if (sum - a + m >= y)
                    case1 = true;
            }
            //find strongest that can't defeat dragon;
            bool case2 = false;
            if (hero[0] <= x - 1)
            {
                it--;
                ll a = *it;
                it++;
                if (m - (x - a) >= 0 && sum - a + (m - (x - a)) >= y)
                    case2 = true;
            }

            if (case1 || case2)
            {
                hi = m - 1;
                ans = std::min(ans, m);
            }
            else
            {
                lo = m + 1;
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}
