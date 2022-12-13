//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> mn[n + 1], mx[n + 1];

        for (int i = 0; i <= n; i++)
        {
            mn[i].resize(m + 1, 1e9);
            mx[i].resize(m + 1, -1);
        }

        mn[0][1] = -1;
        mn[1][0] = -1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mn[i][j] = std::min(mn[i][j-1] + i, mn[i-1][j] + j);
                mx[i][j] = std::max(mx[i][j-1] + i, mx[i-1][j] + j);
            }
        }

        if(k >= mn[n][m] && k <= mx[n][m]){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
