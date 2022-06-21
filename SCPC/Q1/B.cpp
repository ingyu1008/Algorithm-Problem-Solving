#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        std::cout << "Case #" << tc << "\n";

        int n, t;
        std::cin >> n >> t;

        std::string s;
        std::cin >> s;

        std::vector<int> ans(n);
        std::vector<int> cnt(n, 0);

        for (int i = 0; i < n; i++)
        {
            int a = (i < t) ? 1 : (s[i - t] - '0');
            int b = (i + t < n) ? (s[i + t] - '0') : 1;

            if (a == 1 && b == 1)
            {
                ans[i] = 1;
                if (i >= t)
                    cnt[i - t]++;
                if (i + t < n)
                    cnt[i + t]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == 0)
                continue;

            int a = (i < t) ? 2 : cnt[i - t];
            int b = (i + t < n) ? cnt[i + t] : 2;

            if (a >= 2 && b >= 2)
            {
                ans[i] = 0;
                if (i >= t)
                    cnt[i - t]--;
                if (i + t < n)
                    cnt[i + t]--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            std::cout << ans[i];
        }
        std::cout << "\n";
    }

    return 0;
}