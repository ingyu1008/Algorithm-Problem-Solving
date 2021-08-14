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
#include <bitset>
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
int visited[1024];
ll ans = mod;

void solve(ll a, ll b, ll dep)
{
    if (a >= 1024 || visited[a] <= dep)
        return;

    // std::cout << a << " ";

    visited[a] = dep;

    if (a == b)
        ans = std::min(ans, dep);

    int cnt = mod;
    if (a > 0) // minus 1
    {
        solve(a - 1, b, dep + 1);
    }
    if (a < 1023) // plus 1
    {
        solve(a + 1, b, dep + 1);
    }

    for (int i = 0;; i++)
    {
        if ((1 << (i + 1)) > a)
            break;
        solve(a ^ (1 << i), b, dep + 1);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string A, B;
    std::cin >> A >> B;
    std::bitset<10> AA(A);
    std::bitset<10> BB(B);

    std::fill_n(visited, 1024, mod);
    solve(AA.to_ullong(), BB.to_ullong(), 0);

    std::cout << ans;

    return 0;
}
