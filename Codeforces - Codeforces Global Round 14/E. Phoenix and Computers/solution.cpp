//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll dp[401][401]; //dp[채워진 컴퓨터 개수][연속한 컴퓨터 개수]
ll fact[401];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 400; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }

    dp[1][1] = 1;
    dp[2][2] = 1;

    for (int i = 3; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][1] = (dp[i][1] + 2 * dp[i - 2][j] * (2 * j - 2 + (j == 1))) % M;
        }
        for (int j = 2; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * 3;
        }
    }

    //debug
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cout << dp[i][j] << " ";
        }
        std::cout << "\n";
    }

    ll ans = 0;
    for (int j = 1; j <= N; j++)
    {
        ans = (ans + dp[N][j] * (2 * j - 2 + (j == 1))) % M;
    }

    std::cout << ans << "\n";

    return 0;
}
