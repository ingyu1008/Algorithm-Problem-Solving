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
        std::vector<bool> v(26);

        std::cin >> N;
        std::string s;
        std::cin >> s;

        v[s[0] - 'A'] = true;

        bool flag = true;

        for (int i = 1; i < N; i++)
        {
            if (s[i] != s[i - 1])
            {
                if (v[s[i] - 'A'])
                {
                    flag = false;
                    break;
                }
                v[s[i] - 'A'] = true;
            }
        }

        std::cout << ((flag) ? "YES\n" : "NO\n");
    }

    return 0;
}
