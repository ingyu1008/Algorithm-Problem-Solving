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

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
	while (T--)
	{
		int N, L, R;
        std::cin >> N >> L >> R;

        //dp[i][j][k] = i번째 까지 봤을때, L = j, R = k인 경우의 수
        ll dp[21][21][21];
        std::fill((ll*)dp, (ll*)dp+21*21*21, 0LL);
        dp[1][1][1] = 1;

        for(int i = 1; i < N; i++){
            for(int j = 1; j < N; j++){
                for(int k = 1; k < N; k++){
                    dp[i+1][j+1][k] += dp[i][j][k];
                    dp[i+1][j][k+1] += dp[i][j][k];
                    dp[i+1][j][k] += dp[i][j][k] * (i-1); 
                }
            }
        }

        std::cout << dp[N][L][R] << "\n";
    }

    return 0;
}
