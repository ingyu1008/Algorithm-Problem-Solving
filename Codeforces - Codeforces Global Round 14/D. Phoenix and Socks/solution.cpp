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
        int N, L, R;
        std::cin >> N >> L >> R;

        std::vector<int> cntL(N + 1), cntR(N + 1), cnt(N + 1);

        for (int i = 0, c; i < L; i++)
        {
            std::cin >> c;
            cntL[c]++;
        }
        for (int i = 0, c; i < R; i++)
        {
            std::cin >> c;
            cntR[c]++;
        }

        if (L == R)
        {
            //색만 바꾸면 되는 경우
            int sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += std::abs(cntR[i] - cntL[i]);
            }
            std::cout << sum / 2 << "\n";
        }
        else if (L > R)
        {
            int cost = 0;
            //짝만 바꾸면 되는 경우
            for (int i = 1; i <= N; i++)
            {
                if (L == R)
                    break;
                while (L > R && cntL[i] - 1 >= cntR[i] + 1)
                {
                    cntL[i]--;
                    cntR[i]++;
                    L--;
                    R++;
                    cost++;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                if (L == R)
                    break;
                while (L > R && cntL[i] - 1 >= cntR[i])
                {
                    cntL[i]--;
                    cntR[i]++;
                    L--;
                    R++;
                    cost++;
                }
            }
            //색만 바꾸면 되는 경우
            int sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += std::abs(cntR[i] - cntL[i]);
            }
            std::cout << cost + sum / 2 << "\n";
        }
        else if (L < R)
        {
            int cost = 0;
            //짝만 바꾸면 되는 경우
            for (int i = 1; i <= N; i++)
            {
                if (L == R)
                    break;
                while (L < R && cntL[i] + 1 <= cntR[i] - 1)
                {
                    cntL[i]++;
                    cntR[i]--;
                    L++;
                    R--;
                    cost++;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                if (L == R)
                    break;
                while (L < R && cntL[i] <= cntR[i] - 1)
                {
                    cntL[i]++;
                    cntR[i]--;
                    L++;
                    R--;
                    cost++;
                }
            }
            //색만 바꾸면 되는 경우
            int sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += std::abs(cntR[i] - cntL[i]);
            }
            std::cout << cost + sum / 2 << "\n";
        }
    }

    return 0;
}
