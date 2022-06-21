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

struct Node {
    int depth;
    int par[20];
    std::vector<int> adj;

    Node(): depth(0){}

    void addEdge(int x){
        adj.push_back(x);
    }
};

struct Tree {
    std::vector<Node> tree;
    
    Tree(int N){
        tree.resize(N+1);
    }

    void addEdge(int a, int b){
        tree[a].addEdge(b);
        tree[b].addEdge(a);
    }

    void dfs(int node, int par){
        tree[node].depth = tree[par].depth + 1;
        tree[node].par[0] = par;
        for(int i = 1; i <= 20; i++){
            tree[node].par[i] = tree[tree[node].par[i-1]].par[i-1];
        }

        for(auto next: tree[node].adj){
            if(next == par) continue;
            dfs(next, node);
        }        
    }

    int lca(int a, int b){
        if(tree[a].depth < tree[b].depth) std::swap(a, b);
        if(tree[a].depth > tree[b].depth){
            int diff = tree[a].depth - tree[b].depth;
            int k = 0;
            while(diff){
                if(diff & 1) a = tree[a].par[k];
                diff >>= 1;
                k++;
            }
        }

        if(a == b) return a;

        for(int k = 19; k >= 0; k--){
            if(tree[a].par[k] != tree[b].par[k]){
                a = tree[a].par[k];
                b = tree[b].par[k];
            }
        }

        return tree[a].par[0];
    }

    int lca(int r, int u, int v){
        std::vector<int> vec = {lca(r, u), lca(r, v), lca(u, v)};
        std::sort(vec.begin(), vec.end(), [&](const int &a, const int &b) -> bool {
            return tree[a].depth > tree[b].depth;
        });

        return vec[0];
    }
};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    Tree tree(N);

    for(int i = 1, a, b; i < N; i++){
        std::cin >> a >> b;
        tree.addEdge(a, b);
    }

    tree.dfs(1, 1);

    int M;
    std::cin >> M;
    for(int i = 0, a, b, c; i < M; i++){
        std::cin >> a >> b >> c;
        std::cout << tree.lca(a, b, c) << "\n";
    }

    return 0;
}
