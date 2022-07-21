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

    int N, K;
    std::cin >> N >> K;

    int x[3] = {15*60, 18*60, 21*60};
    
    std::vector<std::string> v;

    while(x[0] < (N+1) * 24 * 60){
        for(int i = 0; i < 3; i++){
            if((x[i] / (24*60)) == (N)){
                std::string hh = std::to_string((x[i]/60)%24);
                if(hh.size() == 1) hh = "0" + hh;

                std::string mm = std::to_string(x[i]%60);
                if(mm.size() == 1) mm = "0" + mm;
                v.push_back(hh + ":"+ mm);
            }
            x[i] += 24*60 + K;
        }
    }

    std::cout << v.size() << "\n";

    for(auto s: v){
        std::cout << s << "\n";
    }

    return 0;
}
