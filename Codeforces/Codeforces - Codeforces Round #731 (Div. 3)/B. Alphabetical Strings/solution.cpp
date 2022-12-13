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
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        std::string s;
        std::cin >> s;
        int lo = s.find_first_of('a');
        int hi = s.find_last_of('a');
        std::string ans = "YES\n";
        if (lo != hi || lo == -1)
        {
            ans = "NO\n";
        }
        for (int i = 1; i < s.size(); i++)
        {
            char c = 'a' + i;
            int x = s.find_first_of(c);
            int y = s.find_last_of(c);
            if (x != y || x == -1)
            {
                ans = "NO\n";
                break;
            }
            if (x == lo - 1)
                lo--;
            else if (x == hi + 1)
                hi++;
            else
            {
                ans = "NO\n";
                break;
            }
        }

        std::cout << ans;
    }

    return 0;
}
