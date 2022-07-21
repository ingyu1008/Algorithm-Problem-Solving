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
int dist[1010][1010];

std::vector<int> dx, dy;

void bfs(int x, int y, int dist){
    
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.push({{x, y}, 0});

    while(!q.empty()){
        auto p = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if(dist[p.first][p.second] > 0) continue;
        dist[p.first][p.second] = d;

        for(int i = 0; i < dx.size(); i++){
            if(dist[p.first + dx[i]][p.second + dy[i]] > 0)continue;
            q.push({{p.first + dx[i], p.second + dy[i]}, d+1});
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int M;
    std::cin >> M;
    while(M--){
        int a, b;
        std::cin >> a >> b;
        dx.push_back(a);
        dy.push_back(b);
    }

    bfs()

    int T;
    while(T--){

    }
    

    return 0;
}
