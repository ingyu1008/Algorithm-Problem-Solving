#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    if (N & 1 && v[0] & 1 && v.back() & 1)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}