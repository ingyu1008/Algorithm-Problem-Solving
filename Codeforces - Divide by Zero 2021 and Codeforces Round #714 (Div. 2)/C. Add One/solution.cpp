#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll mod = 1e9 + 7;
ll dp[10][202020];

ll find2(ll n, ll m)
{
    if (dp[n][m] != 0)
        return dp[n][m];
    if (m == 0)
    {
        return 1;
    }
    if (m >= 10 - n)
    {
        return dp[n][m] = (find2(1, m - (10 - n)) + find2(0, m - (10 - n)))%mod;
    }
    else
    {
        return 1;
    }
}

ll find(ll n, ll m)
{
    ll ret = 0;
    while (n)
    {
        ret += find2(n % 10, m);
        ret %= mod;
        n /= 10;
    }
    return ret;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m;
        std::cin >> n >> m;
        std::cout << find(n, m) << "\n";
    }

    return 0;
}