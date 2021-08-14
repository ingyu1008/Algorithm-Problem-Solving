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
#include <queue>
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

    int Q;
    std::cin >> Q;

    std::map<std::string, std::priority_queue<ll>> mp;

    std::string s;
    int q;
    int k;
    ll ans = 0;
    while (Q--)
    {
        std::cin >> q;
        if (q == 1)
        {
            std::cin >> s >> k;
            for (int i = 0, x; i < k; i++)
            {
                std::cin >> x;
                mp[s].push(x);
            }
        }
        else
        {
            std::cin >> s >> k;
            k = std::min((int)mp[s].size(), k);

            for (int i = 0; i < k; i++)
            {
                ans += mp[s].top();
                mp[s].pop();
            }
        }
    }

    std::cout << ans;

    return 0;
}
