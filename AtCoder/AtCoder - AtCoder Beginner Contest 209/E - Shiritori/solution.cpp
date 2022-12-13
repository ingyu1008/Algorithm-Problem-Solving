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

ll mod = 1e18;

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

const ll next = 380204032LL;

ll dp[1 << 18]; // 1 = win, 2 = not win;
std::vector<std::pair<ll, int>> v;
std::vector<std::string> sv;

ll dfs(int node)
{
    // std::cout << node << "\n";
    if (dp[node])
        return dp[node];
    dp[node] = mod;

    ll low = 0;
    for (ll k = sv[node].size() - 3; k < sv[node].size(); k++)
    {
        ll x;
        if (sv[node][k] >= 'A' && sv[node][k] <= 'Z')
        {
            x = sv[node][k] - 'A' + 26;
        }
        else
        {
            x = sv[node][k] - 'a';
        }
        // std::cout << x << "aaa\n";
        low += x * powmod(52, 7 - (k - sv[node].size() + 3));
    }
    int lo = 0;
    int hi = v.size() - 1;
    int ans = v.size();
    while (lo <= hi)
    {
        int m = (lo + hi) >> 1;
        if (v[m].first >= low)
        {
            ans = std::min(ans, m);
            hi = m - 1;
        }
        else
        {
            lo = m + 1;
        }
    }

    // std::cout << low << " " << node << " " << v[ans].first << " " << low + next << "\n";

    if (ans == v.size() || v[ans].first >= low + next)
    {
        return dp[node] = 2;
    }

    while (ans < v.size() && v[ans].first < low + next)
    {
        // std::cout << "node : " << node << " dp[node] = " << dp[node] << "\n";
        ll x = dfs(v[ans].second);
        if (x == 2)
        {
            dp[node] = x;
        }
        ans++;
    }
    // std::cout << dp[node] << "\n";

    if (dp[node] > 3)
        return dp[node] = mod;

    if (dp[node] & 1)
    {
        dp[node] = 2;
    }
    else
    {
        dp[node] = 1;
    }
    return dp[node];
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    v.resize(N);
    sv.resize(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> sv[i];
        std::string s = sv[i];
        ll hash = 0;
        for (ll k = 7; 7 - k < s.size(); k--)
        {
            ll x;
            if (s[7 - k] >= 'A' && s[7 - k] <= 'Z')
            {
                x = s[7 - k] - 'A' + 26;
            }
            else
            {
                x = s[7 - k] - 'a';
            }
            hash += x * powmod(52, k);
        }
        v[i].first = hash;
        v[i].second = i;
    }

    std::sort(v.begin(), v.end());

    dfs(0);

    for (int i = 0; i < N; i++)
    {
        dfs(i);
        if (dp[i] == 1)
        {
            std::cout << "Aoki\n";
        }
        else if (dp[i] == 2)
        {
            std::cout << "Takahashi\n";
        }
        else
        {
            std::cout << "Draw\n";
        }
    }

    return 0;
}
