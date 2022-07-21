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

ll map[20][20];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> map[i][j];
        }
    }

    ll ans = -1e18;
    ll jongjinmax = -1e18;
    for(int i = 0; i < (1 << N); i++){
        ll minwoo = 0;
        ll jongjin = 0;
        for(int j = 0; j < N; j++){
            ll all = 0;
            ll selected = 0;
            for(int k = 0; k < N; k++){
                if((i  & (1 << k))){
                    selected += map[k][j];
                }
                all += map[k][j];
            }

            selected = std::max(selected, all - selected);

            jongjin += selected;
            minwoo += all-selected;
        }
        if(jongjin > jongjinmax){
            jongjinmax = jongjin;
            ans = -1e18;
        }
        ans = std::max(ans, minwoo);
    }

    std::cout << ans << "\n";

    return 0;
}
