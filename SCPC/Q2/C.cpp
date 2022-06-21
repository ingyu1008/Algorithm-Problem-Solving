#include <iostream>
#include <vector>
#include <map>

typedef long long ll;
ll v[55][55];
ll dp[55][55][55];
int N, K;
ll solve(int r, int c, int k, bool prop = true)
{
    if (r <= 0 || r > N || k == 0)
        return 0;
    if (prop && dp[r][c][k] > -1e18)
        return dp[r][c][k];
    int s = std::max(0, c - k);
    int e = std::min(N, c + k - 1);
    ll ret = v[r][e] - v[r][s];
    ret += solve(r, c, k - 1);
    if (prop)
    {
        for (int i = 1; i < k; i++)
        {
            ret += solve(r - i, c, k - i, false);
            ret += solve(r + i, c, k - i, false);
        }
        dp[r][c][k] = ret;
    }
    return ret;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << "\n";
        std::cin >> N >> K;

        if (N > 50)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    std::cin >> v[1][1];
                }
            }
            std::cout << "0\n";
            continue;
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                for (int k = 1; k <= K; k++)
                {
                    dp[i][j][k] = -1e18;
                }
            }
        }

        ll mx = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                std::cin >> dp[i][j][1];
                v[i][j] = dp[i][j][1] + v[i][j - 1];
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == 1 || i == N || j == 1 || j == N)
                {
                    for (int k = 1; k <= K; k++)
                    {
                        mx = std::max(mx, solve(i, j, k));
                    }
                }
                else
                {
                    mx = std::max(mx, solve(i, j, K));
                }
            }
        }
        std::cout << mx << "\n";
    }

    return 0;
}