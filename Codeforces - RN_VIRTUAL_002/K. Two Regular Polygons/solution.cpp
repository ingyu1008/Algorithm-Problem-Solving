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
        int A, B;
        std::cin >> A >> B;
        std::cout << ((A%B)?"NO\n":"YES\n");
    }

    return 0;
}