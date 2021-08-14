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

struct Node
{
    ll sum, lazy;
} tree[4040404];

void lazy_push(int node, int l, int r)
{
    if (l != r)
    {
        tree[node * 2].lazy += tree[node].lazy;
        tree[node * 2 + 1].lazy += tree[node].lazy;
    }

    tree[node].sum += tree[node].lazy * (r - l + 1);
    tree[node].lazy = 0;
}

Node merge(Node o1, Node o2)
{
    Node node;
    node.sum = o1.sum + o2.sum;
    node.lazy = 0;
    return node;
}

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].sum = v[l];
        tree[node].lazy = 0;
    }
    else
    {
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
}

void update(int node, int l, int r, int s, int e, ll diff)
{
    lazy_push(node, l, r);
    if (l > e || r < s)
    {
        return;
    }
    if (l >= s && r <= e)
    {
        tree[node].lazy += diff;
        lazy_push(node, l, r);
        return;
    }

    int m = (l + r) / 2;
    update(node * 2, l, m, s, e, diff);
    update(node * 2 + 1, m + 1, r, s, e, diff);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

ll query(int node, int l, int r, int s, int e)
{
    lazy_push(node, l, r);
    if (l > e || r < s)
    {
        return 0;
    }
    if (l >= s && r <= e)
    {
        return tree[node].sum;
    }

    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M, K;
    std::cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> v[i];
    }

    init(1, 1, N);

    // for (int i = 1; i <= N; i++)
    // {
    //     std::cout << query(1, 1, N, 1, i) << " ";
    // }

    M += K;
    ll a, b, c, d;
    while (M--)
    {
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            std::cin >> d;
            update(1, 1, N, b, c, d);
        }
        else
        {
            std::cout << query(1, 1, N, b, c) << "\n";
        }
    }

    return 0;
}
