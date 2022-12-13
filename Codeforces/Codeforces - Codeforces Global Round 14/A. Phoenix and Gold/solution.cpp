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
        int N, x;
        std::cin >> N >> x;
        std::vector<int> v(N);

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
            sum += v[i];
        }

        std::cout << ((sum == x) ? "NO\n" : "YES\n");
        if (sum != x)
        {
            sum = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (sum + v[i] != x)
                {
                    sum += v[i];
                    std::cout << v[i] << " ";
                }
                else
                {
                    v.push_back(v[i]);
                }
            }
        }
    }

    return 0;
}
