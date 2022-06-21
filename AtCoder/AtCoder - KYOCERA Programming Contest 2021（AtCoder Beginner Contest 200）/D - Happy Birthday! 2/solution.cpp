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
#include <queue>
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
    std::vector<int> v(N);
    std::map<int, std::set<int>> mp;

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
        std::queue<std::pair<int, std::set<int>>> q;
        for (auto p : mp)
        {
            int sum = v[i] % 200;
            std::set<int> st;
            st.insert(i);
            for (auto x : p.second)
            {
                sum = (sum + v[x]) % 200;
                st.insert(x);
            }

            if (mp.find(sum) != mp.end())
            {
                std::cout << "Yes\n";
                std::cout << mp[sum].size() << " ";
                for (auto y : mp[sum])
                {
                    std::cout << y + 1 << " ";
                }
                std::cout << "\n"
                          << st.size() << " ";
                for (auto y : st)
                {
                    std::cout << y + 1 << " ";
                }
                goto end;
            }
            q.push({sum, st});
        }

        std::set<int> s;
        s.insert(i);

        if (mp.find(v[i] % 200) != mp.end())
        {
            std::cout << "Yes\n";
            std::cout << mp[v[i] % 200].size() << " ";
            for (auto y : mp[v[i] % 200])
            {
                std::cout << y + 1 << " ";
            }
            std::cout << "\n"
                      << s.size() << " ";
            for (auto y : s)
            {
                std::cout << y + 1 << " ";
            }
            goto end;
        }

        q.push({v[i] % 200, s});

        while (!q.empty())
        {
            mp[q.front().first] = q.front().second;
            q.pop();
        }
    }

    std::cout << "No\n";
    return 0;

end:
    return 0;
}
