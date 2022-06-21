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
std::vector<int> pre, in, post;

void solve(int prel, int prer, int inl, int inr){
    if(prel > prer) return;
    if(prel == prer){
        post.push_back(pre[prel]);
        return;
    }

    int inmid = inl;
    while(inmid <= inr && pre[prel] != in[inmid]) inmid++;
    int premid = prel+(inmid - inl) + 1;
    solve(prel+1, premid-1, inl, inmid-1);
    solve(premid, prer, inmid+1, inr);
    post.push_back(pre[prel]);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for(int i = 0; i < T; i++){
        pre.clear();
        in.clear();
        post.clear();

        int N;
        std::cin >> N;

        for(int j = 0, x; j < N; j++) std::cin >> x, pre.push_back(x);
        for(int j = 0, x; j < N; j++) std::cin >> x, in.push_back(x);
        
        solve(0, N-1, 0, N-1);

        for(int j = 0; j < N; j++) std::cout << post[j] << " ";
        std::cout << "\n";
    }
    

    return 0;
}
