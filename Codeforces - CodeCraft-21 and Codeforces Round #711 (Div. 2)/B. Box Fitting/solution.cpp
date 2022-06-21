#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, W;
        std::cin >> N >> W;
        std::map<int, int> mp;
        int x;
        for (int i = 0; i < N; i++)
        {
            std::cin >> x;
            mp[x]++;
        }

        int h = 1;
        int sz = 0;

    loop:

        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            while (it->second > 0 && sz + it->first <= W)
            {
                it->second--;
                sz += it->first;
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > 0)
            {
                h++;
                sz = 0;
                goto loop;
            }
        }
        std::cout << h << "\n";
    }

    return 0;
}