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
        int N;
        std::cin >> N;
        std::vector<std::string> v(N);
        int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
            for (int j = 0; j < N; j++)
            {
                if (v[i][j] == '*')
                {
                    if (r1 < 0)
                        r1 = i;
                    else if (r1 != i)
                        r2 = i;
                    if (c1 < 0)
                        c1 = j;
                    else if (c1 != j)
                        c2 = j;
                }
            }
        }

        if (r2 < 0)
        {
            r2 = r1 - 1 + 2 * (r1 == 0);
        }
        if (c2 < 0)
        {
            c2 = c1 - 1 + 2 * (c1 == 0);
        }

        v[r1][c2] = '*';
        v[r2][c1] = '*';
        v[r2][c2] = '*';

        for(int i = 0; i < N; i++){
            std::cout << v[i] << "\n";
        }
    }

    return 0;
}