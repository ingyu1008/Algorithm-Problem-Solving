#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <random>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <tuple>
#include <map>
#include <set>
#define MOD 1000000007LL
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;
typedef std::pair<ll, ll> pll;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
ll rnpow(ll x, ll y)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return rnpow(x, y - 1) * x % MOD;
    ll res = rnpow(x, y >> 1LL) % MOD;
    return res * res % MOD;
}
int gcd(int i, int j) { return i ? gcd(j % i, i) : j; }
ll gcd(ll i, ll j) { return i ? gcd(j % i, i) : j; }
ll fac(ll x) { return x ? fac(x - 1) * x : 1; }

int ar[33][2002];
int primes[30] = {2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239};
int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ar[i][j] = 1 + primes[i] * j;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", ar[i][j]);
        }
        puts("");
    }
    return 0;
}

