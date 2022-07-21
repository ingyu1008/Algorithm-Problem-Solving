/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
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

std::vector<std::pair<ll, ll>> v[202020];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int V, E;
    std::cin >> V >> E;

    std::priority_queue<std::pair<std::pair<int, ll>, int>> pq;

    for(int i = 0; i < E; i++){
        ll a, b, c;
        std::cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }

    int s, e;
    std::cin >> s >> e;
    pq.push({{0, 0LL}, s});

    std::vector<std::pair<int, ll>> dist(V+1, {1e9, 1e18});
    dist[s] = {0, 0};

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        
        int cnt = -p.first.first;
        ll d = -p.first.second;
        int cur = p.second;

        // std::cout << cur << " " << cnt << " " << d << "\n";

        if(dist[cur].first < cnt) continue;
        else if(dist[cur].first == cnt && dist[cur].second < d) continue;

        for(auto next : v[p.second]){
            if(dist[next.first].first < cnt + 1) continue;
            else if(dist[next.first].first == cnt + 1 && dist[next.first].second <= d + next.second) continue;
            dist[next.first].first = cnt + 1;
            dist[next.first].second = d + next.second;
            pq.push({{-(cnt + 1), -(d + next.second)}, next.first});
        }
    }

    if(dist[e].second >= 1e18) std::cout << "-1";
    else std::cout << dist[e].second;


    return 0;
}
