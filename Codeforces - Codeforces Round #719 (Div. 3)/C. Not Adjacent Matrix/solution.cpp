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
        int N;
        std::cin >> N;

        if (N == 1)
        {
            std::cout << "1\n";
        }
        else if (N == 2)
        {
            std::cout << "-1\n";
        }
        else
        {
            int arr[100][100];

            for (int i = 0; i < (N * N); i++)
            {
                int idx = (2 * i) % (N * N) + ((N & 1) == 0) * ((2 * i) / (N * N));
                arr[idx / N][idx % N] = i + 1;
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    std::cout << arr[i][j] << " ";
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
