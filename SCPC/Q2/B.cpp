#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll mn[9][1 << 8];
ll dx[8] = {0, 0, 1, 1, 2, 2, 3, 3};
ll dy[8] = {1, 2, 0, 3, 0, 3, 1, 2};
std::vector<std::pair<ll, ll>> v(8);
std::vector<ll> dist[8];
ll mnx, mny, mxx, mxy;

ll calc(ll xx, ll yy, ll K, int i, int j)
{
    return std::abs(xx + dx[j] * K - v[i].first) + std::abs(yy + dy[j] * K - v[i].second);
}

ll solve(ll xx, ll yy, ll K)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            dist[i][j] = calc(xx, yy, K, i, j);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < (1 << 8); j++)
        {
            mn[i][j] = 1e18;
        }
    }

    mn[0][0] = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int c = 0; c < 8; c++)
        {
            for (int j = 0; j < (1 << 8); j++)
            {
                if (j & (1 << c))
                    continue;
                mn[i + 1][j | (1 << c)] = std::min(mn[i + 1][j | (1 << c)], mn[i][j] + dist[i][c]);
            }
        }
    }

    return mn[8][(1 << 8) - 1];
}

ll fory(ll xx, ll K)
{
    ll loy = mny - 2e8;
    ll hiy = mxy + 2e8;
    ll mn = 1e18;
    while (loy <= hiy)
    {
        ll m = (loy + hiy) >> 1;

        ll am1 = solve(xx, m, K);
        ll am2 = solve(xx, m + 1, K);

        if (am1 > am2)
        {
            loy = m + 1;
            mn = std::min(mn, am2);
        }
        else
        {
            hiy = m - 1;
            mn = std::min(mn, am1);
        }
    }

    return mn;
}

int main(void)
{
    // std::cin.tie(0);
    // std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int i = 0; i < 8; i++)
    {
        dist[i].resize(8);
    }

    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << "\n";
        ll mn = 1e18;

        ll K;
        std::cin >> K;

        mnx = 1e18;
        mxx = -1e18;
        mny = 1e18;
        mxy = -1e18;

        for (int i = 0; i < 8; i++)
        {
            std::cin >> v[i].first >> v[i].second;
            mnx = std::min(mnx, v[i].first);
            mxx = std::max(mxx, v[i].first);
            mny = std::min(mny, v[i].second);
            mxy = std::max(mxy, v[i].second);
        }

        ll lox = mnx - 2e8;
        ll hix = mxx;

        while (lox <= hix)
        {
            ll m = (lox + hix) >> 1;

            ll am1 = fory(m, K);
            ll am2 = fory(m + 1, K);

            if (am1 > am2)
            {
                lox = m + 1;
                mn = std::min(mn, am2);
            }
            else
            {
                hix = m - 1;
                mn = std::min(mn, am1);
            }
        }
        std::cout << mn << "\n";
    }

    return 0;
}