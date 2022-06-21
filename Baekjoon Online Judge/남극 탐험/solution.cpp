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

enum OP {
    BRIDGE = 0,
    PENGUINS = 1,
    EXCURSION = 2,
};

struct Query {
    int op, s, e;
};

int par[30303];
ll pen[30303];

int hldroot[30303], inv[30303], chainDepth[30303];

int sz[30303];

std::vector<int> v[30303];

void dfs(int node, int parent) {
    sz[node] = 1;

    for (int& next : v[node]) {
        if (next == parent) continue;
        par[next] = node;
        dfs(next, node);
        int tmp = sz[next];
        sz[node] += sz[next];

        if (v[node][0] == parent || sz[v[node][0]] < tmp) {
            std::swap(v[node][0], next);
        }
    }
}

struct Node {
    ll sum;
};

std::vector<Node> et;

void hld(int node, int parent) {
    inv[node] = et.size();
    et.push_back({ pen[node] });

    for (int& next : v[node]) {
        if (next == parent) continue;
        if (next == v[node][0]) {
            hldroot[next] = hldroot[node];
            chainDepth[next] = chainDepth[node];
        } else {
            hldroot[next] = next;
            chainDepth[next] = chainDepth[node] + 1;
        }
        hld(next, node);
    }
}

std::vector<Node> tree(123123);

void init(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = et[l].sum;
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);

    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

void update(int node, int l, int r, int idx, ll val) {
    if (l > idx || r < idx) return;
    if (l == r) {
        tree[node].sum = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, idx, val);
    update(node * 2 + 1, mid + 1, r, idx, val);

    tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
}

ll query(int node, int l, int r, int s, int e) {
    if (l > e || r < s)
        return 0;
    if (l >= s && r <= e)
        return tree[node].sum;
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, s, e) + query(node * 2 + 1, mid + 1, r, s, e);
}

int uf[30303];

int find(int x) {
    if (uf[x] == x) return x;
    return uf[x] = find(uf[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    uf[x] = y;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        uf[i] = i;
        std::cin >> pen[i];
    }

    int Q;
    std::cin >> Q;

    std::string op;
    int x, y;
    std::vector<Query> queries;

    for (int i = 0; i < Q; i++) {
        std::cin >> op >> x >> y;
        Query q;
        q.op = op[0] == 'b' ? BRIDGE : (op[0] == 'p' ? PENGUINS : EXCURSION);
        q.s = x;
        q.e = y;
        queries.push_back(q);

        if (q.op == BRIDGE) {
            if (find(x) == find(y)) continue;
            uni(x, y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }

    for (int i = 1; i <= N; i++) {
        uf[i] = i;
    }

    par[1] = 1;
    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        if (par[i] == 0) {
            par[i] = i;
            dfs(i, 0);
        }
    }

    hldroot[1] = 1;
    chainDepth[1] = 0;
    hld(1, 0);

    for (int i = 1; i <= N; i++) {
        if (hldroot[i] == 0) {
            hldroot[i] = i;
            hld(i, 0);
        }
    }

    init(1, 0, et.size() - 1);

    for (Query q : queries) {
        if (q.op == BRIDGE) {
            if (find(q.s) == find(q.e)) {
                std::cout << "no\n";
            } else {
                uni(q.s, q.e);
                std::cout << "yes\n";
            }
        } else if (q.op == PENGUINS) {
            update(1, 0, et.size() - 1, inv[q.s], q.e);
        } else {
            ll ans = 0;
            int x = q.s;
            int y = q.e;

            if (find(x) != find(y)) {
                std::cout << "impossible\n";
                continue;
            }

            if (chainDepth[x] < chainDepth[y]) std::swap(x, y);
            while (chainDepth[x] != chainDepth[y]) {
                ans += query(1, 0, et.size() - 1, inv[hldroot[x]], inv[x]);
                x = par[hldroot[x]];
            }

            while (hldroot[x] != hldroot[y]) {
                ans += query(1, 0, et.size() - 1, inv[hldroot[x]], inv[x]);
                x = par[hldroot[x]];
                ans += query(1, 0, et.size() - 1, inv[hldroot[y]], inv[y]);
                y = par[hldroot[y]];
            }

            if (inv[x] > inv[y]) std::swap(x, y);

            ans += query(1, 0, et.size() - 1, inv[x], inv[y]);

            std::cout << ans << "\n";
        }
    }





    return 0;
}
