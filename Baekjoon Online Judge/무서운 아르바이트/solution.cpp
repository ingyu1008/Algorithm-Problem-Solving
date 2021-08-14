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

ll solve(int l, int r, std::vector<ll> &v)
{
    int m = (l + r) / 2;
    ll mx = v[m];
    ll cnt = 1;
    ll h = v[m];

    if (l == r)
    {
        return mx;
    }
    else if (l > r)
    {
        return 0;
    }

    int ll = m - 1;
    int rr = m + 1;

    mx = std::max(mx, solve(l, m - 1, v));
    mx = std::max(mx, solve(m + 1, r, v));

    while (ll >= l || rr <= r)
    {
        if (ll < l)
        {
            h = std::min(h, v[rr]);
            rr++;
        }
        else if (rr > r)
        {
            h = std::min(h, v[ll]);
            ll--;
        }
        else if (v[ll] >= v[rr])
        {
            h = std::min(h, v[ll]);
            ll--;
        }
        else if (v[ll] < v[rr])
        {
            h = std::min(h, v[rr]);
            rr++;
        }

        cnt++;
        mx = std::max(mx, cnt * h);
    }

    return mx;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<ll> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    std::cout << solve(0, N - 1, v);

    return 0;
}
