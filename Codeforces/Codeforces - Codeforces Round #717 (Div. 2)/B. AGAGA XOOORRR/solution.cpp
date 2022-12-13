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

        std::vector<int> v(N);
        std::vector<int> xorp(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
            xorp[i] = v[i];
            if (i)
                xorp[i] = (xorp[i - 1] ^ v[i]);
        }

        bool possible = false;

        for (int i = 1; i < N - 1; i++)
        {
            for (int j = i; j < N - 1; j++)
            {
                if (xorp[i - 1] == (xorp[j] ^ xorp[i - 1]) && xorp[i - 1] == (xorp[N - 1] ^ xorp[j]))
                {
                    possible = true;
                }
            }
        }

        if (xorp[N - 1] == 0)
        {
            possible = true;
        }

        if (possible)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

    return 0;
}
