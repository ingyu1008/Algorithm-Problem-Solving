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

    int T;
    std::cin >> T;
    while (T--)
    {
        ll W, H, x1, y1, x2, y2, w, h;
        std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

        ll zz, wz, zh, wh;
        zz = wz = zh = wh = 1e18;
        if ((x2 - x1) + w <= W)
        {
            zz = std::min(zz, std::max(0LL, w - x1));
            zh = std::min(zh, std::max(0LL, w - x1));
            wz = std::min(wz, std::max(0LL, x2 - (W - w)));
            wh = std::min(wh, std::max(0LL, x2 - (W - w)));
        }
        if ((y2 - y1) + h <= H)
        {
            zz = std::min(zz, std::max(0LL, h - y1));
            wz = std::min(wz, std::max(0LL, h - y1));
            zh = std::min(zh, std::max(0LL, y2 - (H - h)));
            wh = std::min(wh, std::max(0LL, y2 - (H - h)));
        }
        ll ans = std::min(std::min(zz, wz), std::min(zh, wh));
        if (ans == 1e18)
            ans = -1;
        std::cout << ans << "\n";
    }

    return 0;
}
