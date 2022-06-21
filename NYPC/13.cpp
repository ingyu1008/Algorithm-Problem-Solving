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

struct Node
{
    ll mn;
} tree[1 << 22];

Node merge(Node o1, Node o2)
{
    Node node;
    node.mn = std::min(o1.mn, o2.mn);
    return node;
}
// 왼쪽으로 한번 오른쪽으로 한번 스위핑 하면됨

void init(int node, int l, int r)
{
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<std::pair<ll, ll>> v;

    for (ll i = 0, x, t; i < N; i++)
    {
        std::cin >> x;
        v.push_back({x, t * N});
    }

    return 0;
}