#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::vector<int> v;

    for (int i = 0; i * (i - 1) / 2 <= 1000000; i++)
    {
        v.push_back(i * (i + 1) / 2);
    }

    int T;
    std::cin >> T;
    while (T--)
    {
        int x;
        std::cin >> x;

        int lo = 0;
        int hi = v.size() - 1;

        int mn = hi;

        while (lo <= hi)
        {
            int m = (lo + hi) >> 1;

            if (v[m] >= x)
            {
                hi = m - 1;
                mn = std::min(mn, m + (x + 1 == v[m]));
            }
            else if (v[m] < x)
            {
                lo = m + 1;
            }
        }
        std::cout << mn << "\n";
    }

    return 0;
}