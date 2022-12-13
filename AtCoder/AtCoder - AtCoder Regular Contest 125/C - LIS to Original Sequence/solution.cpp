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

    int N, K;
    std::cin >> N >> K;

    std::vector<int> v(K);
    std::vector<std::vector<int>> li(K + 1);

    for (int i = 0; i < K; i++)
    {
        std::cin >> v[i];
    }

    for (int j = 1; j < v[0]; j++)
    {
        li[1].push_back(j);
    }

    for (int i = 1, j = v[0] + 1; i < K; i++)
    {
        for (int k = j; k < v[i]; k++)
        {
            li[i - 1].push_back(k);
        }
        j = v[i] + 1;
    }

    for (int j = v[K - 1] + 1; j <= N; j++)
    {
        li[K - 1].push_back(j);
    }

    for (int i = 0; i < K; i++)
    {
        if (li[i].size() > 0)
        {
            int z = std::min(i + 1, K - i);
            int div = li[i].size() / z + 1;
            int offset = (li[i].size() % div + div - 1) % div;
            int cnt = 0;
            while (cnt < li[i].size())
            {
                for (int j = (offset + div) % div; j < li[i].size(); j += div)
                {
                    std::cout << li[i][j] << " ";
                    cnt++;
                }
                offset--;
            }
        }
        std::cout << v[i] << " ";
    }
    if (li[K].size() > 0)
    {
        int div = li[K].size() / K + 1;
        int offset = (li[K].size() % div + div - 1) % div;
        int cnt = 0;
        while (cnt < li[K].size())
        {
            for (int j = (offset + div) % div; j < li[K].size(); j += div)
            {
                std::cout << li[K][j] << " ";
                cnt++;
            }
            offset--;
        }
    }

    return 0;
}
