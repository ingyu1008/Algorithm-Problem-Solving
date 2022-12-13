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
		std::string s;
        std::cin >> s;

        ll l = 0;
        ll r = s.size() -1;

        while(l < r){
            if(s[l] == '0')break;
            l++;
        }

        while(l < r){
            if(s[r] == '0')break;
            r--;
        }

        bool x[2] = {false, false};

        for(int i = l ; i <= r; i++){
            x[s[i] - '0'] = true;
        }

        if(x[0]){
            if(x[1]){
                std::cout << "2\n";
            } else {
                std::cout << "1\n";
            }
        } else {
            std::cout << "0\n";
        }
    }

    return 0;
}
