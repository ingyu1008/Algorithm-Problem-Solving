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

ll tree[101010];

void update(int idx, ll diff)
{
    while (idx < 101010)
    {
        tree[idx] += diff;
        idx += (idx & (-idx));
    }
}

ll sum(int idx)
{
    ll res = 0;
    while (idx > 0)
    {
        res += tree[idx];
        idx -= (idx & (-idx));
    }
    return res;
}
int n, m;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;

        std::fill_n(tree, 101010, 0);

        std::vector<std::pair<int, int>> v(n * m);
        std::vector<int> vv(n * m);
        std::map<int, std::vector<int>> mp;

        for (int i = 0; i < n * m; i++)
        {
            std::cin >> v[i].first;
            v[i].second = -i;
        }

        std::sort(v.begin(), v.end());

        for (int i = 0; i < n * m; i++)
        {
            mp[v[i].first].push_back(i + 1);
        }

        for (auto &p : mp)
        {
            std::vector<int> &vec = p.second;
            std::sort(vec.begin(), vec.end(), [](int a, int b) -> bool
                      {
                          int aa = ((a - 1) / m);
                          int bb = ((b - 1) / m);

                          if(aa != bb) return aa < bb;
                          else return a > b;
                      });
            ;
        }

        for (int i = 0; i < n * m; i++)
        {
            auto it = mp[v[i].first].rbegin();
            vv[-v[i].second] = *it;
            mp[v[i].first].pop_back();
        }

        ll ans = 0;

        for (int i = 0; i < n * m; i++)
        {
            ans += sum(vv[i]) - sum(vv[i] - ((vv[i] - 1) % m) - 1);
            update(vv[i], 1);
        }

        std::cout << ans << "\n";
    }

    return 0;
}
