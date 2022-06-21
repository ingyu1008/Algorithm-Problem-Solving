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
int sz[101010], par[101010];

int dfs(int node, int parent = 0) {
    sz[node] = 1;

    for (auto& p : v[node]) {
        int next = p.first.first;
        if (sz[next] || next == parent)continue;

        // e2v[p.first.second] = next;

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
    // inv[node] = et.size();
    // et.push_back({ cost });

    for (int i = 0; i < v[node].size(); i++) {
        if (par[v[node][i].first.first]) continue;

        if (i) par[v[node][i].first.first] = v[node][i].first.first;
        else par[v[node][i].first.first] = par[node];

        hld(v[node][i].first.first, v[node][i].second);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, R, Q;
    std::cin >> N >> R >> Q;

    for (int i = 1; i < N; i++) {
        int x, y;
        std::cin >> x >> y;

        v[x].push_back({ { y, i }, 0 });
        v[y].push_back({ { x, i }, 0 });
    }

    dfs(R);
    for(int i = 0; i < 101010; i++){
        par[i] = 0;
    }
    // hld(R, 0);

    for(int i = 0; i < Q; i++){
        int x;
        std::cin >> x;

        std::cout << sz[x] << "\n";
    }

    return 0;
}
