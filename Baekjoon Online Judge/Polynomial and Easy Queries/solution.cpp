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
    ll f, g, flazy, glazy, x; // x valid only if l == r
} tree[1 << 21];

ll sparseTbF[100004][22];
ll sparseTbG[100004][22];

ll process(Node node)
{
    ll result = node.x;
    // 2^19 >= 500,000
    for (int i = 0; i < 21; i++)
    {
        if (node.f & (1 << i))
        {
            // std::cout << " >> " << sparseTbF[result][i + 1] << "\n";
            result = sparseTbF[result][i + 1];
        }
    }
    for (int i = 0; i < 21; i++)
    {
        if (node.g & (1 << i))
        {
            // std::cout << " >> " << sparseTbG[result][i + 1] << "\n";
            result = sparseTbG[result][i + 1];
        }
    }
    return result;
}

void lazy(int node, int l, int r)
{
    if (l != r)
    {
        tree[node * 2].flazy += tree[node].flazy;
        tree[node * 2].glazy += tree[node].glazy;
        tree[node * 2 + 1].flazy += tree[node].flazy;
        tree[node * 2 + 1].glazy += tree[node].glazy;
    }
    tree[node].f += tree[node].flazy;
    tree[node].g += tree[node].glazy;

    tree[node].flazy = 0;
    tree[node].glazy = 0;
}

void query1(int node, int l, int r, int s, int e)
{
    lazy(node, l, r);
    if (l > e || r < s)
    {
        return;
    }
    if (l >= s && r <= e)
    {
        tree[node].flazy++;
        lazy(node, l, r);
        return;
    }

    int m = (l + r) >> 1;
    query1(node * 2, l, m, s, e);
    query1(node * 2 + 1, m + 1, r, s, e);
}

void query2(int node, int l, int r, int s, int e)
{
    lazy(node, l, r);
    if (l > e || r < s)
    {
        return;
    }
    if (l >= s && r <= e)
    {
        tree[node].glazy++;
        lazy(node, l, r);
        return;
    }

    int m = (l + r) >> 1;
    query2(node * 2, l, m, s, e);
    query2(node * 2 + 1, m + 1, r, s, e);
}

ll query3(int node, int l, int r, int x)
{
    lazy(node, l, r);
    if (l > x || r < x)
    {
        return 0;
    }
    if (l == r)
    {
        return process(tree[node]);
    }

    int m = (l + r) >> 1;
    return query3(node * 2, l, m, x) + query3(node * 2 + 1, m + 1, r, x);
}

void initSparseTb()
{
    for (ll j = 0; j < 100003; j++)
    {
        sparseTbF[j][0] = j;
        sparseTbF[j][1] = (2 * j * j + 100002) % 100003;
        sparseTbG[j][0] = j;
        sparseTbG[j][1] = ((j) * ((4 * j * j + 100000) % 100003)) % 100003;
    }
    for (int i = 2; i < 22; i++)
    {
        for (int j = 0; j < 100003; j++)
        {
            sparseTbF[j][i] = sparseTbF[sparseTbF[j][i - 1]][i - 1];
            sparseTbG[j][i] = sparseTbG[sparseTbG[j][i - 1]][i - 1];
        }
    }
}
std::vector<ll> v;

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = {0, 0, 0, 0, v[l]};
        return;
    }

    int m = (l + r) >> 1;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    initSparseTb();

    // std::cout << sparseTbG[sparseTbF[2][1]][1] << "\n";

    int N, Q;
    std::cin >> N >> Q;
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    init(1, 0, N - 1);

    int t, l, r;

    while (Q--)
    {
        std::cin >> t;
        if (t == 1)
        {
            std::cin >> l >> r;
            query1(1, 0, N - 1, l - 1, r - 1);
        }
        else if (t == 2)
        {
            std::cin >> l >> r;
            query2(1, 0, N - 1, l - 1, r - 1);
        }
        else if (t == 3)
        {
            std::cin >> l;
            std::cout << query3(1, 0, N - 1, l - 1) << "\n";
        }
    }

    return 0;
}
