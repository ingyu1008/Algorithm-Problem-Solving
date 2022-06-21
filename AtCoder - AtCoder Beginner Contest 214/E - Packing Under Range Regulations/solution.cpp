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
        int N;
        std::cin >> N;

        std::vector<std::pair<ll, ll>> v(N);
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i].first >> v[i].second;
        }
        std::sort(v.begin(), v.end());

        ll l = 1;
        ll r = 1;
        bool flag = true;
        std::deque<ll> dq;
        for (int i = 0; i < N; i++)
        {
            l = v[i].first;
            r = v[i].second;

            if (dq.empty())
            {
                dq.push_back(l);
            }
            else if (dq.back() < r)
            {
                dq.push_back(std::max(l, dq.back() + 1));
            }
            else if (dq.front() > l)
            {
                dq.push_front(dq.front() - 1);
            }
            else
            {
                flag = false;
                break;
            }
        }

        std::cout << ((flag) ? "Yes\n" : "No\n");
    }

    return 0;
}
