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

int mod = 1e9 + 7;

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
std::vector<int> v[101010];
int sz[101010], par[101010], depth[101010], hldroot[101010], inv[101010], hldDepth[101010];

void dfs(int node, int parent) {
    sz[node] = 1;
    for (int& next : v[node]) {
        if (next == parent) continue;
        par[next] = node;
        depth[next] = depth[node] + 1;
        dfs(next, node);
        int tmp = sz[next];
        sz[node] += sz[next];

        if (v[node][0] == parent || sz[v[node][0]] < tmp) {
            std::swap(v[node][0], next);
        }
    }
}

struct Node {
    int minDepth = mod, num = -1;
};

std::vector<Node> et;

void hld(int node, int parent) {
    inv[node] = et.size();
    et.push_back({ depth[node], node });

    for (int& next : v[node]) {
        if (next == parent) continue;
        if (next == v[node][0]) {
            hldroot[next] = hldroot[node];
            hldDepth[next] = hldDepth[node];
        } else {
            hldroot[next] = next;
            hldDepth[next] = hldDepth[node] + 1;
        }
        hld(next, node);
    }
}

std::vector<Node> tree(404040);

void init(int node, int l, int r) {
    if (l == r) {
        tree[node].minDepth = mod;
        tree[node].num = -1;
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);

    tree[node].minDepth = mod;
    tree[node].num = -1;
}

void update(int node, int l, int r, int pos) {
    if (l > pos || r < pos) return;
    if (l == r) {
        if (tree[node].minDepth == mod) {
            tree[node].minDepth = et[l].minDepth;
            tree[node].num = et[l].num;
        } else {
            tree[node].minDepth = mod;
            tree[node].num = -1;
        }

        return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, pos);
    update(node * 2 + 1, mid + 1, r, pos);

    tree[node].minDepth = mod;
    tree[node].num = -1;

    if (tree[node * 2].minDepth > tree[node * 2 + 1].minDepth) {
        tree[node].minDepth = tree[node * 2 + 1].minDepth;
        tree[node].num = tree[node * 2 + 1].num;
    } else {
        tree[node].minDepth = tree[node * 2].minDepth;
        tree[node].num = tree[node * 2].num;
    }
}

Node query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) return { mod, -1 };
    if (l >= s && r <= e) {
        return tree[node];
    }

    int mid = (l + r) / 2;
    Node left = query(node * 2, l, mid, s, e);
    Node right = query(node * 2 + 1, mid + 1, r, s, e);

    if (left.minDepth < right.minDepth) {
        return left;
    } else if (left.minDepth > right.minDepth) {
        return right;
    } else if (left.minDepth == right.minDepth) {
        return left;
    }
}


void query1(int& N, int i) {
    update(1, 0, N - 1, inv[i]);
}

void query2(int& N, int v) {
    Node ans = { mod, -1 };
    while (hldroot[v] != 1) {
        Node tmp = query(1, 0, N - 1, inv[hldroot[v]], inv[v]);
        if (ans.minDepth > tmp.minDepth) {
            ans = tmp;
        }
        v = par[hldroot[v]];
    }

    Node tmp = query(1, 0, N - 1, inv[hldroot[v]], inv[v]);
    if (ans.minDepth > tmp.minDepth) {
        ans = tmp;
    }
    std::cout << ans.num << '\n';
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    par[1] = 1;
    dfs(1, 0);

    hldroot[1] = 1;
    hldDepth[1] = 0;
    hld(1, 0);

    init(1, 0, N - 1);

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a == 1) {
            query1(N, b);
        } else {
            query2(N, b);
        }
    }

    return 0;
}
