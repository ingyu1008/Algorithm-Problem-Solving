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

ll v[5][101010];
ll dist[5][101010];
std::vector<std::pair<pii, pii>> query;
std::vector<ll> ans;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void dijkstra(int& N, int L, int R, int k) {
    for (int i = 0; i < N; i++) {
        for (int j = L; j <= R; j++) {
            dist[i][j] = 1e18;
        }
    }
    int m = (L + R) >> 1;
    std::priority_queue<std::pair<ll, std::pair<int, int>>, std::vector<std::pair<ll, std::pair<int, int>>>, std::greater<std::pair<ll, std::pair<int, int>>>> pq;
    pq.push(std::make_pair(0, std::make_pair(k, m)));
    dist[k][m] = 0;
    while (!pq.empty()) {
        ll cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (dist[r][c] < cost) continue;

        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];

            if (rr < 0 || rr >= N || cc < L || cc > R) continue;

            if (dist[rr][cc] > dist[r][c] + v[rr][cc]) {
                dist[rr][cc] = dist[r][c] + v[rr][cc];
                pq.push(std::make_pair(dist[rr][cc], std::make_pair(rr, cc)));
            }
        }
    }
}

void solve(int& N, int l, int r, std::vector<int>& queries) {
    if (l > r || queries.empty()) return;
    int m = (l + r) >> 1;
    std::vector<int> L, R;
    for (int k = 0; k < N; k++) {
        dijkstra(N, l, r, k);
        for (int& q : queries) {
            ans[q] = std::min(ans[q], dist[query[q].first.first][query[q].first.second] + dist[query[q].second.first][query[q].second.second] + v[k][m]);
            if (!k && !(query[q].first.second <= m && query[q].second.second >= m)) {
                if (query[q].first.second <= m) {
                    L.push_back(q);
                } else {
                    R.push_back(q);
                }
            }
        }
    }
    solve(N, l, m - 1, L);
    solve(N, m + 1, r, R);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> v[i][j];

    int Q;
    std::cin >> Q;
    std::vector<int> queries;

    for (int i = 0; i < Q; i++) {
        int r1, c1, r2, c2;
        queries.push_back(i);
        std::cin >> r1 >> c1 >> r2 >> c2;
        if(c1 > c2) std::swap(c1, c2), std::swap(r1, r2);
        query.push_back({ { r1 - 1, c1 - 1 }, { r2 - 1, c2 - 1 } });
    }
    ans.resize(Q, 1e18);

    solve(N, 0, M - 1, queries);

    for (int i = 0; i < Q; i++)
        std::cout << ans[i] << '\n';

    return 0;
}
