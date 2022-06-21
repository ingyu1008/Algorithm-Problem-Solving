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

int grundy[3000001];
bool flag[3000001][20];

std::vector<int> fib;

int grun(int n)
{
    if (grundy[n] >= 0)
        return grundy[n];
    std::fill_n(flag[n], 20, false);
    for (int j = 0; j < fib.size(); j++)
    {
        if (n - fib[j] >= 0)
        {
            flag[n][grun(n - fib[j])] = true;
        }
    }
    for (int j = 0; j < 20; j++)
    {
        if (!flag[n][j])
        {
            return grundy[n] = j;
        }
    }
    return grundy[n] = 0;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    fib.push_back(1);
    fib.push_back(2);
    while (fib.back() <= 3000000)
    {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    std::fill_n(grundy, 3000001, -1);
    grundy[0] = 0;

    int N, x, ans = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> x;
        ans ^= grun(x);
    }

    std::cout << ((ans) ? "koosaga" : "cubelover") << "\n";

    return 0;
}
