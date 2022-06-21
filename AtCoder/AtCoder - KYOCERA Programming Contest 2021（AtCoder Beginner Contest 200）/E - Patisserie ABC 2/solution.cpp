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

int main(void)
{
    // std::cin.tie(0);
    // std::ios_base::sync_with_stdio(false);

    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> v(3 * N + 1, 0);

    ll sum;

    for (ll i = 3; i <= 3 * N; i++)
    {
        ll now = ((((i - 1) * (i - 2)) / 2ULL) * (i - 3)) / 3ULL;
        v[i] = v[i - 1] + now;
        if (v[i] >= K)
        {
            sum = i - 1;
            break;
        }
    }

    std::cout << sum << "\n";
    //found sum
    ll beauty;

    std::vector<ll> vv(3 * N + 1, 0);
    for (ll i = std::max(1ULL, sum - 2 * N); i <= 3 * N; i++)
    {
        if (i + 2 > sum)
        {
            vv[i] = vv[i - 1];
        }
        else
        {
            ll now = sum - i - 1;
            vv[i] = vv[i - 1] + now;
            if (vv[i] >= K)
            {
                beauty = i - 1;
                break;
            }
        }
    }

    //beauty found

    std::cout << beauty << "\n";

    for (ll taste = 1; taste < sum - beauty; taste++)
    {
        if (v[sum - 1] + vv[beauty] == K)
        {
            std::cout << beauty << " " << taste << " " << sum - beauty - taste << "\n";
            break;
        }
        K--;
    }

    return 0;
}
