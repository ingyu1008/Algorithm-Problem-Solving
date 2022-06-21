#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << ": ";
        int cnt = 0;

        int R, C;
        std::cin >> R >> C;

        std::vector<int> v[R];

        for (int i = 0; i < R; i++)
        {
            v[i].resize(C);
            for (int j = 0; j < C; j++)
            {
                std::cin >> v[i][j];
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (v[i][j] == 0)
                    continue;
                int minr = i;
                int maxr = i;
                int minc = j;
                int maxc = j;

                while (minr > 0 && v[minr - 1][j] == 1)
                    minr--;
                while (maxr < R - 1 && v[maxr + 1][j] == 1)
                    maxr++;
                while (minc > 0 && v[i][minc - 1] == 1)
                    minc--;
                while (maxc < C - 1 && v[i][maxc + 1] == 1)
                    maxc++;

                int top = i - minr + 1;
                int bottom = maxr - i + 1;
                int right = maxc - j + 1;
                int left = j - minc + 1;

                cnt += std::max(std::min(top / 2, right) - 1, 0);
                cnt += std::max(std::min(top / 2, left) - 1, 0);
                cnt += std::max(std::min(bottom / 2, right) - 1, 0);
                cnt += std::max(std::min(bottom / 2, left) - 1, 0);
                cnt += std::max(std::min(top, right / 2) - 1, 0);
                cnt += std::max(std::min(top, left / 2) - 1, 0);
                cnt += std::max(std::min(bottom, right / 2) - 1, 0);
                cnt += std::max(std::min(bottom, left / 2) - 1, 0);
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}