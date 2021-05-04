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
        int N, M, X;
        std::cin >> N >> M >> X;

        std::vector<std::pair<int, int>> v(N);
        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i].first;
            v[i].second = i;
        }
        std::sort(v.begin(), v.end());
        std::vector<ll> s(M);
        std::vector<int> ans(N);
        for (int i = 0; i < N; i++)
        {
            s[i % M] += v[i].first;
            ans[v[i].second] = i % M;
        }
        ll mn = 1e9;
        ll mx = 0;
        for (int i = 0; i < M; i++)
        {
            mn = std::min(mn, s[i]);
            mx = std::max(mx, s[i]);
        }

        if (mx - mn > X)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
            for (int i = 0; i < N; i++)
            {
                std::cout << ans[i] + 1 << " ";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
