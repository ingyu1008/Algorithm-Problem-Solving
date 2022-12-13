/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
// #pragma GCC optimize("unroll-loops")
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
        int k, n, m;
        std::cin >> k >> n >> m;

        std::vector<int> nn(n);
        std::vector<int> mm(m);
        for (int i = 0; i < n; i++)
        {
            std::cin >> nn[i];
        }
        for (int i = 0; i < m; i++)
        {
            std::cin >> mm[i];
        }

        int nnn = 0;
        int mmm = 0;

        std::vector<int> ans;
        ans.clear();

        while ((nnn < n) || (mmm < m))
        {
            int cnt = 0;
            while (nnn < n && nn[nnn] <= k)
            {
                k += ((nn[nnn] == 0) ? 1 : 0);
                ans.push_back(nn[nnn]);
                nnn++;
                cnt++;
            }
            while (mmm < m && mm[mmm] <= k)
            {
                k += ((mm[mmm] == 0) ? 1 : 0);
                ans.push_back(mm[mmm]);
                mmm++;
                cnt++;
            }
            if (cnt == 0)
            {
                ans.clear();
                break;
            }
        }

        while (nnn < n && nn[nnn] <= k)
        {
            k += ((nn[nnn] == 0) ? 1 : 0);
            ans.push_back(nn[nnn]);
            nnn++;
        }
        while (mmm < m && mm[mmm] <= k)
        {
            k += ((mm[mmm] == 0) ? 1 : 0);
            ans.push_back(mm[mmm]);
            mmm++;
        }

        if (ans.size() == n + m)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                std::cout << ans[i] << " ";
            }
            std::cout << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}
