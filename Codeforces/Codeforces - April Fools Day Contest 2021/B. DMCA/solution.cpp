#include <iostream>
#include <cmath>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int a;
    std::cin >> a;

    int b = 0;
    while (a)
    {
        b += a % 10;
        a /= 10;
    }

    std::cout << b%9 + (b%9 == 0)*9 << "\n";

    return 0;
}