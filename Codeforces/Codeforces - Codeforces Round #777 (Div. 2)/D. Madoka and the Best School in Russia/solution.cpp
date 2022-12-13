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
		ll x, d;
        std::cin >> x >> d;

        int cnt = 0;
        while(x % d == 0){
            x /= d;
            cnt++;
        }

        int ans = 0;

        if(cnt & 1) ans ++;
        if(cnt >= 2) ans ++;

        int div = 0;
        for(int i = 2; i < 50000; i++){
            int t = 0;
            while(x % i == 0){
                x /= i;
                t++;
            }
            div++;
            if(t > 2) div++;
        }

        if(cnt >= 2 && div >= 2) ans ++;

        if(ans >= 2) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }

    return 0;
}
