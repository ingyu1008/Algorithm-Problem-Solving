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

std::vector<std::vector<ll>> b;
std::vector<std::vector<ll>> v;
std::vector<ll> ans;
std::vector<ll> realans;
ll mx = 0;
std::map<ll, std::vector<ll>> mp;

bool cmp(const std::vector<ll> &a, const std::vector<ll> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i];
        }
    }
    return a[0] > b[0];
}

ll solve(ll depth, ll maxdepth, ll cnt, ll sum = 0)
{
    if (depth == maxdepth)
    {
        auto it = std::lower_bound(b.begin(), b.end(), ans, cmp);

        bool eq = (*it)[0] != 0;
        if (eq)
        {
            for (ll i = 0; i < ans.size(); i++)
            {
                eq &= (ans[i] == (*it)[i]);
            }
        }
        if (eq)
            return 0LL;
        else
        {
            if (mx < sum)
            {
                mx = sum;
                realans = ans;
            }
            return sum;
        }
    }

    ll res = 0;

    for (ll i = v[depth].size() - 1; i >= std::max(0LL, (ll)v[depth].size() - cnt); i--)
    {
        ans[depth] = i + 1;
        ll ret = solve(depth + 1, maxdepth, cnt, sum + v[depth][i]);
        if (ret > res)
        {
            res = ret;
        }
    }
    return res;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    v.resize(N);
    ans.resize(N);
    realans.resize(N);

    for (int i = 0; i < N; i++)
    {
        ll c;
        std::cin >> c;
        for (int j = 0, x; j < c; j++)
        {
            std::cin >> x;
            v[i].push_back(x);
        }
    }

    int M;
    std::cin >> M;
    b.resize(M, std::vector<ll>(N));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> b[i][j];
        }
    }
    b.push_back(std::vector<ll>(N));

    std::sort(b.begin(), b.end(), cmp);

    ll cnt = 0;
    while (true)
    {
        ll prod = 1;
        for (int i = 0; i < N; i++)
        {
            ll sz = v[i].size();
            prod *= std::min(cnt, sz);
        }

        if (prod > M)
            break;

        cnt++;
    }

    solve(0, N, cnt);

    for (auto x : realans)
    {
        std::cout << x << " ";
    }

    return 0;
}
