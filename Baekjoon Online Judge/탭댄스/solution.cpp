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
    int ll, lr, rl, rr;
} tree[1 << 20];

Node merge(const Node &a, const Node &b)
{
    Node node;
    node.ll = std::max(a.ll, b.ll);
    if (a.ll > 0 && b.rl > 0)
        node.ll = std::max(node.ll, a.ll + b.rl);
    if (a.lr > 0 && b.ll > 0)
        node.ll = std::max(node.ll, a.lr + b.ll);

    node.lr = std::max(a.lr, b.lr);
    if (a.ll > 0 && b.rr > 0)
        node.lr = std::max(node.lr, a.ll + b.rr);
    if (a.lr > 0 && b.lr > 0)
        node.lr = std::max(node.lr, a.lr + b.lr);

    node.rl = std::max(a.rl, b.rl);
    if (a.rl > 0 && b.rl > 0)
        node.rl = std::max(node.rl, a.rl + b.rl);
    if (a.rr > 0 && b.ll > 0)
        node.rl = std::max(node.rl, a.rr + b.ll);

    node.rr = std::max(a.rr, b.rr);
    if (a.rl > 0 && b.rr > 0)
        node.rr = std::max(node.rr, a.rl + b.rr);
    if (a.rr > 0 && b.lr > 0)
        node.rr = std::max(node.rr, a.rr + b.lr);

    return node;
}

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = {1, 0, 0, 0};
        return;
    }
    int m = (l + r) >> 1;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int idx)
{
    if (l > idx || r < idx)
        return;
    if (l == r)
    {
        tree[node].ll ^= 1;
        tree[node].rr ^= 1;
        return;
    }
    int m = (l + r) >> 1;
    update(node * 2, l, m, idx);
    update(node * 2 + 1, m + 1, r, idx);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    init(1, 1, N);
    std::cout << tree[1].ll << " " << tree[1].lr << " " << tree[1].rl << " " << tree[1].rr << "\n";

    while (Q--)
    {
        int x;
        std::cin >> x;
        update(1, 1, N, x);
        std::cout << tree[1].ll << " " << tree[1].lr << " " << tree[1].rl << " " << tree[1].rr << "\n";
        // std::cout << std::max(std::max(tree[1].ll, tree[1].lr), std::max(tree[1].rl, tree[1].rr)) << "\n";
    }

    return 0;
}

// RLLRLL