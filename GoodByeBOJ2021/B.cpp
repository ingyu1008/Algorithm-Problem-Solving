/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
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
    
    // 1, 3, 4, 7, 

    ll T;
    std::cin >> T;

    while(T--){
        ll N;
        std::cin >> N;

        if((N%3) == 2 || (N%9) == 0 || ((N%2) == 0) && ((2 + N/2)%3 == 0)){
            std::cout << "TAK\n";
        } else {
            std::cout << "NIE\n";
        }
    }

    return 0;
}