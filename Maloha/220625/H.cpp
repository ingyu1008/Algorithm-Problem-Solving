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
#define MAX 1010

std::vector<int> a[MAX];
int d[MAX];
bool c[MAX];

bool dfs(int x){
    for(int i = 0; i < a[x].size(); i++){
        int t = a[x][i];

        if(c[t]) continue;
        c[t] = true;

        if(d[t] == 0 || dfs(d[t])){
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<std::pair<ll, ll>> X(N+1), Y(N+2);
    for(int i = 1; i <= N; i++) std::cin >> X[i].first >> X[i].second;
    for(int i = 1; i <= N+1; i++) std::cin >> Y[i].first >> Y[i].second;
    
    std::vector<std::pair<ll, int>> order;

    for(int i = 1; i <= N; i++){
        ll mn = 9e18;
        std::vector<std::pair<ll,int>> dist;
        for(int j = 1; j <= N+1; j++){
            ll d = (X[i].first-Y[j].first)*(X[i].first-Y[j].first) + (X[i].second-Y[j].second)*(X[i].second-Y[j].second);
            dist.push_back({d, j});
        }
        std::sort(dist.begin(), dist.end());

        for(int j = 1; j <= N+1; j++){
            a[i].push_back(dist[j-1].second);
        }
        order.push_back({mn, i});
    }
    a[N+1].push_back(1);
    order.push_back({-1, N+1});

    std::sort(order.begin(), order.end());

    int cnt = 0;
    for(auto i : order){
        std::fill(c, c+MAX, false);
        if(dfs(i.second)) cnt++;
    }

    if(cnt == N && d[1] == 0) std::cout << 1;
    else std::cout << -1;
    

    return 0;
}
