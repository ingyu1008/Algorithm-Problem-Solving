#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;
    int q;

    while (Q--)
    {
        std::cin >> q;
        if (q == 2)
            std::cout << "\n";
    }

    return 0;
}