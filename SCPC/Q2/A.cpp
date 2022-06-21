#include <iostream>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << "\n";
        ll R;
        std::cin >> R;

        ll ans = 0;

        for (ll x = -R + 1; x < R; x++)
        {
            ll l = 1;
            ll r = R;
            ll mx = 0;
            while (l <= r)
            {
                ll m = (l + r) >> 1;
                if (x * x + m * m < R * R)
                {
                    mx = std::max(mx, m);
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }

            ans += 2 * mx + 1;
        }
        std::cout << ans << "\n";
    }

    return 0;
}