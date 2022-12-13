#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a % mod;

    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
    {
        b = (b * a) % mod;
    }
    return b % mod;
}

std::vector<ll> fact(202020);

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < 202020; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    int T;
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        std::vector<ll> v(N);
        std::map<ll, ll> mp;
        ll AND = __LONG_LONG_MAX__;
        ll x = 1;

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
            AND &= v[i];
            mp[v[i]]++;
            x *= mp[v[i]];
            x %= mod;
        }

        ll res = 0;
        ll cnt = 0;

        for (int i = 0; i < N; i++)
        {
            if ((AND == v[i]))
            {
                cnt++;
            }
        }

        if (cnt >= 2)
        {
            res = ((cnt - 1) * cnt) % mod;
            res = (res * fact[N - 2]) % mod;
        }

        std::cout << res % mod << "\n";
    }

    return 0;
}