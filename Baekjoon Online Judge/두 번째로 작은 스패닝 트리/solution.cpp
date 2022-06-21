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
#include <queue>
#include <random>
#include <ctime>
#include <functional>

struct Edge {
    ll from, to, cost;
};

std::vector<Edge> edges;
std::vector<std::pair<ll, ll>> mst[50505];
std::vector<Edge> candidate;

ll par[101010][20];
ll mx[101010][20];
ll mx2[101010][20];
ll depth[101010];

void dfs(ll idx)
{
    for (ll j = 1; j < 20; j++)
    {
        par[idx][j] = par[par[idx][j - 1]][j - 1];
        std::vector<ll> v = { mx[idx][j - 1], mx[par[idx][j - 1]][j - 1], mx2[idx][j - 1], mx2[par[idx][j - 1]][j - 1] };
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        mx[idx][j] = v[v.size() - 1];
        mx2[idx][j] = (1 == v.size()) ? 0 : v[v.size() - 2];
    }
    for (ll i = 0; i < mst[idx].size(); i++)
    {
        ll next = mst[idx][i].first;
        if (!par[next][0])
        {
            depth[next] = depth[idx] + 1;
            par[next][0] = idx;
            mx[next][0] = mst[idx][i].second;
            mx2[next][0] = 0;
            dfs(next);
        }
    }
}

ll lca(ll a, ll b, ll c) {
    ll ans = 0;
    ll ans2 = 0;

    if (depth[a] < depth[b])
        std::swap(a, b);
    if (depth[a] > depth[b]) {
        ll diff = depth[a] - depth[b];
        ll k = 0;
        while (diff) {
            if (diff & 1) {
                std::vector<ll> v = { ans, ans2, mx[a][k], mx2[a][k] };
                a = par[a][k];
                std::sort(v.begin(), v.end());
                v.erase(std::unique(v.begin(), v.end()), v.end());

                ans = v[v.size() - 1];
                ans2 = (1 == v.size()) ? 0 : v[v.size() - 2];
            }
            diff >>= 1;
            k++;
        }
    }

    if (a == b) {
        if (ans == c) return ans2;
        return ans;
    }
    for (ll i = 19; i >= 0; i--)
    {
        if (par[a][i] != par[b][i])
        {
            std::vector<ll> v = { ans, ans2,  mx[a][i], mx2[a][i], mx[b][i], mx2[b][i] };
            a = par[a][i];
            b = par[b][i];
            std::sort(v.begin(), v.end());
            v.erase(std::unique(v.begin(), v.end()), v.end());

            ans = v[v.size() - 1];
            ans2 = (1 == v.size()) ? 0 : v[v.size() - 2];
        }
    }
    std::vector<ll> v = { ans, ans2, mx[a][0], mx2[a][0] };
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    ans = v[v.size() - 1];
    ans2 = (1 == v.size()) ? 0 : v[v.size() - 2];
    if (ans == c) return ans2;
    return ans;
}

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

ll parent[50505];

ll find(ll x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(ll a, ll b) {
    a = find(a);
    b = find(b);

    parent[a] = b;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll V, E;
    std::cin >> V >> E;

    std::mt19937 mt(time(NULL));
    std::uniform_int_distribution<ll> dist(1, V);
    auto rand = std::bind(dist, mt);

    for (ll i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    for (ll i = 0; i < E; i++)
    {
        ll x, y, z;
        std::cin >> x >> y >> z;
        if (x > y) std::swap(x, y);
        edges.push_back({ x, y, z + 1 });
    }

    std::sort(edges.begin(), edges.end(), cmp);

    ll cost = 0;

    for (Edge& e : edges) {
        if (find(e.from) != find(e.to)) {
            uni(e.from, e.to);
            mst[e.from].push_back({ e.to, e.cost });
            mst[e.to].push_back({ e.from, e.cost });
            cost += e.cost;
        } else {
            candidate.push_back(e);
        }
    }

    bool flag = true;
    for (ll i = 1; i <= V; i++) {
        flag &= (find(i) == find(1));
    }

    if (!flag) {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<ll> v;

    for (ll t = 0; t < 1; t++) {
        for (ll i = 0; i <= V; i++) {
            depth[i] = 0;
            for (ll j = 0; j < 20; j++) {
                par[i][j] = 0;
                mx[i][j] = 0;
                mx2[i][j] = 0;
            }
        }

        ll start = rand();

        par[start][0] = start;
        mx[start][0] = 0;
        mx2[start][0] = 0;
        dfs(start);

        for (Edge& e : candidate) {
            ll max_cost = lca(e.from, e.to, e.cost);
            ll ans = cost - max_cost + e.cost;
            if (ans > cost && max_cost > 0) {
                v.push_back(ans);
            }
        }
    }

    std::sort(v.begin(), v.end());

    if (v.empty()) std::cout << -1 << std::endl;
    else std::cout << v[0] - (V - 1) << std::endl;

    return 0;
}
