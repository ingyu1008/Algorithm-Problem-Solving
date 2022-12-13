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
#include <cmath>

typedef unsigned long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
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

ll isqrt(ll N){
	ll sqrtN=std::sqrt(N)-1;
	while(sqrtN+1<=N/(sqrtN+1))sqrtN++;
	return sqrtN;
}

ll solve(ll X) {
    if (X < 4) return 1;

    ll sqrt = isqrt(X);
    ll ans = sqrt;
    for (ll i = 2LL; i * i <= sqrt; i++) {
        ll x = i * i;
        ans += solve(i) * (sqrt - x + 1);
    }
    return ans;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll T;
    std::cin >> T;
    while (T--)
    {
        ll X;
        std::cin >> X;
        std::cout << solve(X) << '\n';
    }

    return 0;
}
