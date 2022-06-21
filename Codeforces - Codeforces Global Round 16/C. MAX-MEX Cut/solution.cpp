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
        int N;
        std::cin >> N;
        std::string s, t;
        std::cin >> s >> t;

        ll mx = 0;
        int open = -1;

        if (s[0] != t[0])
            mx = 2;
        else if (s[0] == '0')
        {
            mx = 1;
            open = 0;
        }
        else
        {
            open = 1;
        }

        for (int i = 1; i < N; i++)
        {
            if (s[i] != t[i])
            {
                mx += 2;
                open = -1;
            }
            else if (s[i] == '0')
            {
                if (s[i - 1] != t[i - 1])
                {
                    mx++;
                    open = 0;
                }
                else if (s[i - 1] == '0')
                {
                    mx++;
                    open = 0;
                }
                else if (open == 1)
                {
                    mx += 2;
                    open = -1;
                }
                else
                {
                    mx++;
                    open = 0;
                }
            }
            else
            {
                if (s[i - 1] == t[i - 1] && s[i - 1] == '0')
                {
                    if (open == 0)
                    {
                        open = -1;
                        mx++;
                    } else {
                        open = 1;
                    }
                }
                else
                    open = 1;
            }
        }
        std::cout << mx << "\n";
    }

    return 0;
}
