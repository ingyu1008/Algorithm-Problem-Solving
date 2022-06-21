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
    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << ": ";
        int N, A, B;
        std::cin >> N >> A >> B;
        std::vector<int> v(100),w(100);
        int sum = 0;
        for (int i = 1; i <= N; i++)
        {
            std::cin >> v[i];
            sum += v[i];
        }

        w[2] = 1;
        for (int i = 1; i <= 100; i++)
        {
        }
        std::cout << "IMPOSSIBLE";
        found:
        std::cout << "\n";
    }

    return 0;
}
