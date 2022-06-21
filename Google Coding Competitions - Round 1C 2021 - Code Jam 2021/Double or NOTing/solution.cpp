//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

typedef long long ll;

std::map<ll, ll> mp;

ll solve(ll S, ll E)
{
    // std::cout << S << "\n";

    if (S > 100000)
        return mp[S] = 1e8 + 7;
    if (S == E)
        return mp[S] = 0;
    if (mp.find(S) != mp.end())
        return mp[S];

    ll x = S * 2;
    ll y = S;
    ll z = S;
    ll cnt = 0;
    for (int i = 0; y; i++)
    {
        y >>= 1;
        z ^= (1 << i);
    }

    if (S == 0)
        z = 1;

    mp[S] = 1e8 + 7;

    ll Double = solve(x, E);
    ll Not = solve(z, E);

    return mp[S] = std::min(Double, Not) + 1;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        mp.clear();
        std::cout << "Case #" << t << ": ";
        std::string S, E;
        std::cin >> S >> E;

        ll x = solve(std::stoll(S, 0, 2), std::stoll(E, 0, 2));
        if (x >= 1e8 + 7 || mp.find(std::stoll(S, 0, 2)) == mp.end())
        {
            std::cout << "IMPOSSIBLE\n";
        }
        else
            std::cout << x << "\n";
    }

    return 0;
}
