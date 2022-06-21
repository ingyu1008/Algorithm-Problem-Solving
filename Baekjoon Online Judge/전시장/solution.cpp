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

    int N, S;
    std::cin >> N >> S;

    std::vector<std::pair<int, int>> paint(N);

    for(int i = 0; i < N; i++){
        std::cin >> paint[i].first >> paint[i].second;
    }

    std::sort(paint.rbegin(), paint.rend());
    // 높이 내림차순

    // dp[i] = 높이가 큰 i개만 봤을때 의 답

    std::vector<ll> dp(N+1);
    dp[0] = paint[0].second;

    for(int i = 1; i < N; i++){
        int lo = 0;
        int hi = i-1;
        int idx = -1;
        while(lo <= hi){
            int m = (lo + hi) >> 1;
            if(paint[m].first >= paint[i].first + S){
                idx = std::max(idx, m);
                lo = m+1;
            } else {
                hi = m-1;
            }
        }
        dp[i] = paint[i].second;
        if(i) dp[i] = std::max(dp[i], dp[i-1]);
        if(idx != -1){
            dp[i] = std::max(dp[i], paint[i].second + dp[idx]);
        }
    }

    std::cout << dp[N-1] << "\n";

    return 0;
}
