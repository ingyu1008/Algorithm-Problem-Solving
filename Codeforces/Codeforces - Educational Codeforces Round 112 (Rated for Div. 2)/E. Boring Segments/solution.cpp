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

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<std::pair<int, int>, int>> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }

    std::sort(v.begin(), v.end());

    int minlo = 1;
    int minhi = 10000000;
    int ans = 1e9;

    while (minlo <= minhi)
    {
        int minm = (minlo + minhi) >> 1;

        int maxlo = minm;
        int maxhi = 10000000;

        bool flag = false;

        while (maxlo <= maxhi)
        {
            int maxm = (maxlo + maxhi) >> 1;
            bool possible = true;
            bool start = false;
            bool end = false;
            int last = 1;
            for (int i = 0; i < N; i++)
            {
                if (v[i].second < minm || v[i].second > maxm)
                    continue;
                if (!start && v[i].first.first != 1)
                {
                    possible = false;
                    break;
                }
                if (v[i].first.first > last)
                {
                    possible = false;
                    break;
                }
                if (v[i].first.first == 1)
                    start = true;
                if (v[i].first.second == M)
                    end = true;
                last = v[i].first.second;
                if (start && end)
                    break;
            }
            if (possible && start && end)
            {
                maxhi = maxm - 1;
                // std::cout << ">> " << maxm << " " << minm << "\n";
                ans = std::min(ans, maxm - minm);
                flag = true;
            }
            else
            {
                maxlo = maxm + 1;
            }
        }
        if (flag)
        {
            minlo = minm + 1;
        }
        else
        {
            minhi = minm - 1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
