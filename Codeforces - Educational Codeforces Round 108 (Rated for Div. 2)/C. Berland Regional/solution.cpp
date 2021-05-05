//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

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

        std::vector<ll> u(N), s(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> u[i];
        }
        for (int i = 0; i < N; i++)
        {
            std::cin >> s[i];
        }

        std::vector<ll> v[N];

        for (int i = 0; i < N; i++)
        {
            v[i].push_back(0);
        }

        for (int i = 0; i < N; i++)
        {
            v[u[i] - 1].push_back(s[i]);
        }
        for (int i = 0; i < N; i++)
        {
            std::sort(v[i].rbegin(), v[i].rend() - 1);
            for (int j = 1; j < v[i].size(); j++)
            {
                v[i][j] += v[i][j - 1];
            }
        }

        std::vector<ll> ans(N + 1);

        for (int i = 0; i < N; i++)
        {
            for (int k = 1; k <= N; k++)
            {
                if ((v[i].size() - 1 - (v[i].size() - 1) % k) == 0)
                    break;
                ans[k] += v[i][v[i].size() - 1 - ((v[i].size() - 1) % k)];
            }
        }

        for (int k = 1; k <= N; k++)
        {
            std::cout << ans[k] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
