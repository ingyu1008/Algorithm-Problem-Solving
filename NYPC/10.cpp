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
#include <stack>

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

int tree[1 << 22];

void update(int node, int l, int r, int idx, int diff)
{
    if (l > idx || r < idx)
        return;
    if (l == r)
    {
        tree[node] += diff;
        return;
    }

    int m = (l + r) >> 1;
    update(node * 2, l, m, idx, diff);
    update(node * 2 + 1, m + 1, r, idx, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int l, int r, int s, int e)
{
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node];
    int m = (l + r) >> 1;
    return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> v;
    std::vector<int> start(N + 1);
    std::vector<int> end(N + 1);

    ll ans = 1;

    for (int i = 1, x; i <= 2 * N; i++)
    {
        std::cin >> x;
        if (start[x] == 0)
        {
            start[x] = i;
            v.push_back(x);
        }
        else
        {
            end[x] = i;
        }
    }

    for (int i : v)
    {
        ans += query(1, 1, 2 * N, start[i], end[i]) + 1;
        update(1, 1, 2 * N, end[i], 1);
    }

    std::cout << ans << "\n";

    return 0;
}