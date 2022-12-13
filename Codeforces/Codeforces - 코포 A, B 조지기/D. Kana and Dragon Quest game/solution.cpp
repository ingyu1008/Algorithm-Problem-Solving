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
        int x, n, m;
        std::cin >> x >> n >> m;

        while (x && (n || m))
        {
            if (n && (x / 2) + 10 < x)
            {
                n--;
                x = x / 2 + 10;
            }
            else if (m)
            {
                m--;
                x -= 10;
            }
            else
            {
                n--;
            }
        }

        if (x > 0)
        {
            std::cout << "NO\n";
        }
        else
        {
            std::cout << "YES\n";
        }
    }

    return 0;
}