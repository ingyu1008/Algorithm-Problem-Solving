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
        int N, K;
        std::string S;
        std::cin >> N >> K >> S;

        int cnt = 0;
        for (int i = 0; i < N / 2; i++)
        {
            cnt += (S[i] != S[N - i - 1]);
        }

        std::cout << "Case #" << t << ": " << abs(K - cnt) << "\n";
    }

    return 0;
}
