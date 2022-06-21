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
#include <queue>

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
int N, B, S, R;

std::vector<ll> V(5050);
std::vector<std::pair<int, ll>> v[5050], rv[5050];
ll dist[5050], rdist[5050];
std::vector<ll> dp_before(5050), dp_after(5050);

ll C(ll i, ll j) {
    return (j - i) * (V[j] - V[i - 1]);
}

void dijkstra() {
    for (int i = 0; i <= N; i++) {
        dist[i] = 1e18;
        rdist[i] = 1e18;
    }

    std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>, std::greater<std::pair<ll, int>>> pq;
    pq.push(std::make_pair(0, B + 1));
    dist[B + 1] = 0;
    while (!pq.empty()) {
        ll cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (dist[idx] < cost) continue;

        for (auto& p : v[idx]) {
            int next = p.first;
            ll next_cost = p.second;
            if (dist[next] > dist[idx] + next_cost) {
                dist[next] = dist[idx] + next_cost;
                pq.push(std::make_pair(dist[next], next));
            }
        }
    }

    pq.push(std::make_pair(0, B + 1));
    rdist[B + 1] = 0;
    while (!pq.empty()) {
        ll cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if (rdist[idx] < cost) continue;

        for (auto& p : rv[idx]) {
            int next = p.first;
            ll next_cost = p.second;
            if (rdist[next] > rdist[idx] + next_cost) {
                rdist[next] = rdist[idx] + next_cost;
                pq.push(std::make_pair(rdist[next], next));
            }
        }
    }
}

void solve(int l, int r, int optl, int optr) {
    if (l > r) return;

    int m = (l + r) / 2;
    ll opt = 1e18;
    int optidx = -1;

    for (int k = optl; k <= std::min(m, optr); k++) {
        ll cur = dp_before[k - 1] + C(k, m);
        if (cur < opt) {
            opt = cur;
            optidx = k;
        }
    }

    dp_after[m] = opt;

    solve(l, m - 1, optl, optidx);
    solve(m + 1, r, optidx, optr);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> B >> S >> R;

    for (int i = 1; i <= R; i++) {
        ll x, y, z;
        std::cin >> x >> y >> z;
        v[x].push_back(std::make_pair(y, z));
        rv[y].push_back(std::make_pair(x, z));
    }

    dijkstra();

    for (int i = 1; i <= B; i++) {
        V[i] = dist[i] + rdist[i];
    }

    std::sort(V.begin() + 1, V.begin() + B + 1);

    V[0] = 0;
    for (int i = 1; i <= B; i++) {
        V[i] += V[i - 1];
    }

    dp_before[0] = 0;
    for (int i = 1; i <= B; i++) {
        dp_before[i] = C(1, i);
    }

    for (int i = 2; i <= S; i++) {
        solve(i, B, i, B);
        dp_before = dp_after;
    }

    std::cout << dp_before[B] << '\n';

    return 0;
}
