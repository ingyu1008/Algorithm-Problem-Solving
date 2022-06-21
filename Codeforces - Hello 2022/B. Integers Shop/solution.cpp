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
#include <queue>

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
        int n;
        std::cin >> n;

        std::priority_queue<std::pair<std::pair<ll, ll>, int>> L, R;

        ll x = -1, y = -1, z = 3e9;

        for (int i = 0; i < n; i++)
        {
            ll l, r, c;
            std::cin >> l >> r >> c;

            L.push({ {-l, -c}, i });
            R.push({ {r, -c}, i });

            if ((y - x + 1 < r - l + 1) || (y - x + 1 == r - l + 1 && c < z)) {
                x = l;
                y = r;
                z = c;
            }

            if ((R.top().first.first + L.top().first.first + 1 < y - x + 1) || (R.top().first.first + L.top().first.first + 1 == y - x + 1 && z < -L.top().first.second - R.top().first.second)) {
                std::cout << z << "\n";
            } else {
                std::cout << -L.top().first.second - R.top().first.second << "\n";
            }
        }
    }

    return 0;
}
