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

ll fact[21];
ll dp[10][21];

ll nCr(int n, int r){
    return (fact[n] / fact[r]) / fact[n-r];
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cout << std::fixed << std::setprecision(18);

    int N, C, D, M;
    std::cin >> N >> C >> D >> M;

    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= 20; i++){
        fact[i] = fact[i-1]*i;
    }

    //dp[i][j] = i일 후 j마리에 측정기가 부착되어있을 경우의수
    
    dp[0][0] = 1;
    for(int i = 1; i <= D; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= N; k++){
                if(k + C < j || k < (C - (j-k)) || j < k) continue;
                dp[i][j] += dp[i-1][k] * nCr(k, C - (j-k)) * nCr(N-k, j-k); // dp[i-1][k] * (k)C(C-(j-k)) * (N-k)C(j-k)
            }
            // std::cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << "\n";
        }
    }

    long double ans = dp[D][M];
    
    for(int i = 0; i < D; i++) ans /= nCr(N, C);

    std::cout << ans << "\n";

    return 0;
}
