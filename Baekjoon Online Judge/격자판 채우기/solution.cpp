//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

int dp[200][20000];

int N, M;
int solve(int now, int bitmask)
{
    if (dp[now][bitmask] >= 0)
        return dp[now][bitmask];
    if (now == N * M)
        return (bitmask == 0);
    if (bitmask & 1)
    {
        return dp[now][bitmask] = solve(now + 1, bitmask >> 1);
    }
    int res = solve(now + 1, (bitmask >> 1) + (1 << M - 1));
    if ((bitmask & 2) == 0 && now % M != M - 1)
    {
        res += solve(now + 2, (bitmask >> 2));
    }
    return dp[now][bitmask] = res % 9901;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 20000; j++)
        {
            dp[i][j] = -1;
        }
    }

    std::cin >> N >> M;

    std::cout << solve(0, 0);

    return 0;
}
