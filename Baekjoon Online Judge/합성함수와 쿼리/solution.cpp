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

ll f[200004];
ll sparseTbF[200004][22];

void initSparseTb()
{
    for (ll j = 0; j < 200003; j++)
    {
        sparseTbF[j][0] = j;
        sparseTbF[j][1] = f[j];
    }
    for (int i = 2; i < 22; i++)
    {
        for (int j = 0; j < 200003; j++)
        {
            sparseTbF[j][i] = sparseTbF[sparseTbF[j][i - 1]][i - 1];
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        std::cin >> f[i];
    }

    initSparseTb();

    std::cin >> Q;

    int n, x;

    while (Q--)
    {
        std::cin >> n >> x;
        int ans = x;
        int i = 1;
        while (n > 0)
        {
            if (n & 1)
                ans = sparseTbF[ans][i];
            n >>= 1;
            i++;
        }
        std::cout << ans << "\n";
    }

    return 0;
}