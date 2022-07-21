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

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;

    std::cin >> N >> M;

    std::vector<ll> A(N), B(M);

    ll ans = 0;

    for(int i = 0; i < N; i++) std::cin >> A[i];
    for(int i = 0; i < M; i++) std::cin >> B[i];
    
    std::sort(A.rbegin(), A.rend());
    std::sort(B.begin(), B.end());

    for(int i = 0, j = 0; i < M && j < N; i++, j++){
        if(A[j] - B[i] < 0) break;
        ans += A[j] - B[i];
    }

    std::cout << ans;


    return 0;
}
