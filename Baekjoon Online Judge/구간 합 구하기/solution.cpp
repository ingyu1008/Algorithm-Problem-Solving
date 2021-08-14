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

std::vector<ll> v(1010101);

ll tree[1010101];

void update(int idx, ll x)
{
    ll diff = x - v[idx];
    v[idx] = x;
    while (idx < 1010101)
    {
        tree[idx] += diff;
        idx += (idx & (-idx));
    }
}

ll sum(int idx) //1 ~ idx 까지의 합
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M, K;
    std::cin >> N >> M >> K;

    for (int i = 1, x; i <= N; i++)
    {
        std::cin >> x;
        update(i, x);
    }

    for (int i = 1; i <= N; i++)
    {
        std::cout << sum(i) << "\n";
    }

    M += K;
    ll a, b, c;
    while (M--)
    {
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, c);
        }
        else
        {
            std::cout << sum(c) - sum(b - 1) << "\n";
        }
    }

    return 0;
}
