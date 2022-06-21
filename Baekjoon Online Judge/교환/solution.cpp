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
std::map<std::pair<int,int>, int> mp;

int solve(int N, int K){
    if(K == 0) return N;
    if(mp.find({N,K}) != mp.end()) return mp[{N,K}];

    int ans = -1;
    for(int i = 1; i <= N; i *= 10){
        for(int j = i*10; j <= N; j*= 10){
            if(i == j) continue;
            int ii = (N/i)%10;
            int jj = (N/j)%10;
            if(i*10 > N && jj == 0) continue;
            if(j*10 > N && ii == 0) continue;

            int k = N - i*ii - j*jj + i*jj + j*ii;
            ans = std::max(ans, solve(k, K-1));
        }
    }
    return mp[{N,K}] = ans;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, K;
    std::cin >> N >> K;

    std::cout << solve(N, K) << "\n";

    return 0;
}
