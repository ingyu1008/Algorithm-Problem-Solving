//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << ": ";
        int N, K;
        std::cin >> N >> K;
        std::vector<int> v(N);
        std::set<int> cnt;
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
            cnt.insert(v[i]);
        }

        int mx = *cnt.begin() - 1;
        int mx2 = K - *cnt.rbegin();
        int prev = *cnt.begin();

        if (mx2 > mx)
            std::swap(mx, mx2);

        for (auto it = cnt.begin();;)
        {
            it++;
            if (it == cnt.end())
                break;
            int next = *it;

            int cnt = (next - prev) / 2;

            if (cnt > mx)
            {
                mx2 = mx;
                mx = cnt;
            }
            else if (cnt > mx2)
            {
                mx2 = cnt;
            }

            prev = next;
        }

        int temp = mx + mx2;

        prev = *cnt.begin();

        for (auto it = cnt.begin();;)
        {
            it++;
            if (it == cnt.end())
                break;
            int next = *it;

            temp = std::max(temp, (next - prev - 1));

            prev = next;
        }

        std::cout.precision(7);
        std::cout << std::fixed << 1.0 * temp / K << "\n";
    }

    return 0;
}
