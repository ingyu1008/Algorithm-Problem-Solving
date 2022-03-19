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
std::vector<std::pair<std::pair<int, int>, ll>> v[101010];
int sz[101010], par[101010], hldroot[101010], e2v[101010], inv[101010];
int chainDepth[101010];

struct Node {
    ll cost;
};

std::vector<Node> et;

int dfs(int node, int parent = 0) {
    sz[node] = 1;

    for (auto& p : v[node]) {
        int next = p.first.first;
        if (sz[next] || next == parent)continue;

        e2v[p.first.second] = next;

        par[next] = node;
        int nextsz = dfs(next);
        sz[node] += nextsz;
        if (sz[v[node][0].first.first] < sz[next] || v[node][0].first.first == parent) {
            std::swap(p, v[node][0]);
        }
    }

    return sz[node];
}

void hld(int node, ll cost) {
    inv[node] = et.size();
    et.push_back({ cost });

    for (int i = 0; i < v[node].size(); i++) {
        if (hldroot[v[node][i].first.first]) continue;

        if (i) {
            hldroot[v[node][i].first.first] = v[node][i].first.first;
            chainDepth[v[node][i].first.first] = chainDepth[node] + 1;
        } else {
            hldroot[v[node][i].first.first] = hldroot[node];
            chainDepth[v[node][i].first.first] = chainDepth[node];
        }

        hld(v[node][i].first.first, v[node][i].second);
    }
}

std::vector<ll> tree(404040);

void init(int node, int l, int r) {
    if (l == r) {
        tree[node] = et[l].cost;
        return;
    }

    int mid = (l + r) / 2;

    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int idx, int x) {
    if (l > idx || r < idx) return;

    if (l == r) {
        tree[node] = x;
        return;
    }

    int mid = (l + r) / 2;

    update(node * 2, l, mid, idx, x);
    update(node * 2 + 1, mid + 1, r, idx, x);

    tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
}

ll query(int node, int l, int r, int s, int e) {
    if (l > e || r < s) return 0;
    if (l >= s && r <= e) return tree[node];

    int mid = (l + r) / 2;

    return std::max(query(node * 2, l, mid, s, e), query(node * 2 + 1, mid + 1, r, s, e));
}

void query1(int i, int c) {
    int node = e2v[i];
    update(1, 0, et.size() - 1, inv[node], c);
}

void query2(int u, int v) {
    ll ans = 0;
    
    if(chainDepth[u] < chainDepth[v]) std::swap(u, v);
    while(chainDepth[u] != chainDepth[v]) {
        ans = std::max(ans, query(1, 0, et.size() - 1, inv[hldroot[u]], inv[u]));
        u = par[hldroot[u]];
    }

    while (hldroot[u] != hldroot[v]) {
        ans = std::max(ans, query(1, 0, et.size() - 1, inv[hldroot[u]], inv[u]));
        u = par[hldroot[u]];
        ans = std::max(ans, query(1, 0, et.size() - 1, inv[hldroot[v]], inv[v]));
        v = par[hldroot[v]];
    }

    if (inv[u] > inv[v]) std::swap(u, v);

    if (u != v) {
        ans = std::max(ans, query(1, 0, et.size() - 1, inv[u] + 1, inv[v]));
    }

    std::cout << ans << "\n";
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1; i < N; i++)
    {
        ll x, y, z;
        std::cin >> x >> y >> z;
        v[x].push_back({ {y, i}, z });
        v[y].push_back({ {x, i}, z });
    }

    par[1] = 1;
    dfs(1);

    hldroot[1] = 1;
    chainDepth[1] = 0;
    hld(1, 0);

    init(1, 0, et.size() - 1);

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x == 1) {
            query1(y, z);
        } else {
            query2(y, z);
        }
    }


    return 0;
}
