#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int a;
    std::cin >> a;

    int arr[6];

    for (int i = 0; i < 6; i++)
    {
        arr[i] = a & 1;
        a >>= 1;
    }

    std::swap(arr[0], arr[4]);
    std::swap(arr[2], arr[3]);

    a = 0;
    for (int i = 5; i >= 0; i--)
    {
        a <<= 1;
        a += arr[i];
    }

    std::cout << a << "\n";

    return 0;
}