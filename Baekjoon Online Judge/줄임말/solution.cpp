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

int cntAlphabet[26][101010];

bool exists(char c, int l, int r) // 1 based
{
    int idx = c - 'a';
    return (cntAlphabet[idx][r] - cntAlphabet[idx][l - 1]) > 0;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string S, T;
    std::cin >> S >> T;

    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        for (int j = 0; j < T.size(); j++)
        {
            cntAlphabet[i][j + 1] = cntAlphabet[i][j] + (T[j] == c);
        }
    }
    int x = 0;

    int l = 1;
    int r = T.size();
    for (int i = 0; i < S.size(); i++)
    {
        // std::cout << i << "\n";
        if (!exists(S[i], 1, T.size()))
        {
            x = -2;
            break;
        }
        if (!exists(S[i], l, T.size()))
        {
            l = 1;
            x++;
        }
        int ans = T.size();
        while (l <= r)
        {
            // std::cout << l << " " << r <<  "\n";
            int m = (l + r) >> 1;
            if (!exists(S[i], l, m))
            {
                l = m + 1;
            }
            else
            {
                ans = std::min(ans, m);
                r = m - 1;
            }
        }
        l++;
        r = T.size();
    }

    std::cout << x+1 << "\n";

    return 0;
}
