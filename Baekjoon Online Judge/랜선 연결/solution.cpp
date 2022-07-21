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

std::pair<ll, ll> dp[303][101010];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<ll> A(N+1), B(N+1);

    for(int i = 1; i <= N; i++) std::cin >> A[i] >> B[i];

    for(int i = 1; i <= N; i++){
        for(int j = 1; j < 101010; j++){
            if(A[i] <= j && (B[i] + dp[i-1][j - A[i]].first < dp[i-1][j].first)){
                dp[i][j].first = B[i] + dp[i-1][j - A[i]].first;
                dp[i][j].second = dp[i][j].second + A[i] -1LL;
            } else if(A[i] <= j && (B[i] + dp[i-1][j - A[i]].first == dp[i-1][j].first) && ){

            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int M;
    std::cin >> M;

    ll ans = 1e18;
    for(int i = M; i < 101010; i++){
        if(dp[N][i].second >= M) ans = std::min(ans, dp[N][i].first);
    }

    if(ans == 1e18) std::cout << "-1";
    else std::cout << ans;


    return 0;
}
