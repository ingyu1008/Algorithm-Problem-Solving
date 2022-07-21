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

void print_tc(int t){
    std::cout << "Case #" << t << "\n";
}

ll fact(ll x){
    ll res = 1;
    for(int i = 1; i <= x; i++) res = (res * i) % mod;
    return res;
}

ll nCr(ll n, ll r){
    ll res = fact(n);
    res = (res * powmod(fact(r), mod-2)) % mod;
    res = (res * powmod(fact(n-r), mod-2)) % mod;
    return res;
}

std::vector<ll> v(505050, 0);
std::vector<ll> cnt(505050, 0);

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    ll N, K;
    std::cin >> T;

    for(int t = 1; t <= T; t++){
        print_tc(t);
        std::cin >> N >> K;

        for(int i = 1; i <= N; i++){
            std::cin >> v[i];
            v[i] = v[i] + v[i-1];
        }
        if(v[N] < 0){
            for(int i = 1; i <= N; i++){
                v[i] *= -1;
            }
        }

        ll X = v[N]/K;

        std::fill(cnt.begin(), cnt.begin() + K + 1, 0);

        cnt[0] = 1;
        
        
        ll last = 0;
        ll zr = 0;

        for(int i = 1; i <= N; i++){
            if(X == 0){
                if(v[i] == 0){
                    zr++;
                }
            } else if(v[i]/X > 0 && (v[i]%X) == 0 && (v[i]/X) <= K){
                cnt[v[i] / X] = (cnt[v[i] / X] + cnt[(v[i] / X) - 1])%mod;
                if((v[i] / X) == K) last =  cnt[(v[i] / X) - 1] % mod;
            }
        }

        if(X == 0 && zr >= K){
            last = nCr(zr-1, K-1);
        }

        if(X*K != v[N]) last = 0;

        std::cout << last << std::endl;
        
    }

    return 0;
}