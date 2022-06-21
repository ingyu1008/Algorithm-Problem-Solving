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

bool flag[202020];

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
        int cnt = 0;

        std::fill_n(flag, N + 1, false);

        for (int i = 0; i < N; i++)
        {
            if (t[i] == '0')
                continue;
            if (i - 1 >= 0 && s[i - 1] == '1' && !flag[i - 1])
            {
                flag[i - 1] = true;
                cnt++;
            }
            else if (s[i] == '0' && !flag[i])
            {
                flag[i] = true;
                cnt++;
            }
            else if (i + 1 < N && s[i + 1] == '1' && !flag[i + 1])
            {
                flag[i + 1] = true;
                cnt++;
            }
        }
        std::cout << cnt << "\n";
    }

    return 0;
}
