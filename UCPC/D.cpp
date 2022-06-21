#include <iostream>
#include <vector>

typedef long long ll;

ll dp[4][303030]; //BB BW WB WW
ll last[4][303030];
bool flag[4];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    std::vector<char> s(N);
    std::cin >> s[0];
    int j = 1;

    for(int i = 0; i < N; i++){
        char c;
        std::cin >> c;
        if(c != s[j-1]){
            s[j] = c;
            j++;
        }
    }
    s.resize(j);

    std::vector<ll> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    if (s.size() <= 2)
        std::cout << 0 << "\n";
    else
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 303030; j++)
            {
                dp[i][j] = -1e18;
            }
        }
        if (s[1] == 'B')
        {
            if (s[0] == 'W')
            {
                last[2][1] = v[1];
                dp[2][1] = 0;
            }
            else
            {
                last[0][1] = v[1];
                dp[0][1] = 0;
            }
        }
        else
        {
            if (s[0] == 'W')
            {
                last[3][1] = v[1];
                dp[3][1] = 0;
            }
            else
            {
                last[1][1] = v[1];
                dp[1][1] = 0;
            }
        }
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == 'W')
            {
                dp[1][i] = std::max(std::max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
                last[1][i] = std::max(last[1][i - 1], v[i]);
                dp[3][i] = std::max(std::max(dp[1][i - 1], dp[3][i - 1]), dp[2][i - 1] + last[2][i - 1]);
                last[3][i] = std::max(last[3][i - 1], v[i]);
            }
            else
            {
                dp[0][i] = std::max(std::max(dp[0][i - 1], dp[2][i - 1]), dp[1][i - 1] + last[1][i - 1]);
                last[0][i] = std::max(last[0][i - 1], v[i]);
                dp[2][i] = std::max(std::max(dp[1][i - 1], dp[3][i - 1]), dp[2][i - 1]);
                last[2][i] = std::max(last[2][i - 1], v[i]);
            }

            // std::cout << dp[0][i - 1] << " " << dp[1][i - 1] << " " << dp[2][i - 1] << " " << dp[3][i - 1] << "\n";
        }
        std::cout << std::max(std::max(dp[0][N - 1], dp[1][N - 1]), std::max(dp[2][N - 1], dp[3][N - 1])) << "\n";
    }
    return 0;
}