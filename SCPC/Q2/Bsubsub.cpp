#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll mn[9][1 << 8];
ll dx[8] = {0, 0, 1, 1, 2, 2, 3, 3};
ll dy[8] = {1, 2, 0, 3, 0, 3, 1, 2};
std::vector<std::pair<ll, ll>> v(8);
std::vector<ll> dist[8], x(8), y(8);

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
        for (int i = 0; i < 8; i++)
        {
            std::cin >> v[i].first >> v[i].second;
            x[i] = v[i].first;
            y[i] = v[i].second;
        }
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());

        for (ll i = 0; i < 8; i++)
        {
            x[i] = x[i] - K * (i / 2);
            y[i] = y[i] - K * (i / 2);
        }

        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());

        for (int i = 0; i < 8; i++)
        {
            std::cout << x[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < 8; i++)
        {
            std::cout << y[i] << " ";
        }
        std::cout << "\n";

        // ll tt = solve(x[3], y[3], K);
        // ll tf = solve(x[3], y[4], K);
        // ll ft = solve(x[4], y[3], K);
        // ll ff = solve(x[4], y[4], K);

        for (int i = x[3]; i <= x[4]; i++)
        {
            for (int j = y[3]; j <= y[4]; j++)
            {
                std::cout << i << " " << j << "\n";
                std::cout << solve(i, j, K) << "\n";
            }
        }

        // std::cout << x[3] << " " << y[3] << "\n";
        // std::cout << tt << "\n";
        // std::cout << x[3] << " " << y[4] << "\n";
        // std::cout << tf << "\n";
        // std::cout << x[4] << " " << y[3] << "\n";
        // std::cout << ft << "\n";
        // std::cout << x[4] << " " << y[4] << "\n";
        // std::cout << ff << "\n";

        // std::cout << (x[3] + x[4]) / 2 << " " << (y[3] + y[4]) / 2 << "\n";

        // std::cout << solve((x[3] + x[4]) / 2, (y[3] + y[4]) / 2, K) << "\n";
        // std::cout << std::min(std::min(tt,tf), std::min(ft,ff)) << "\n";
    }

    return 0;
}