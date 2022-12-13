#include <iostream>
#include <vector>
#include <algorithm>

int rec(int start, int now, std::vector<int> &v)
{
    if (start == now)
        return 0;
    else
        return rec(start, v[now] - 1, v) + 1;
}

int main(void)
{

    int Q;
    std::cin >> Q;
    while (Q--)
    {
        int N;
        std::cin >> N;

        std::vector<int> v(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
        }

        for (int i = 0; i < N; i++)
        {
            std::cout << rec(i, v[i] - 1, v) + 1 << " ";
        }
        std::cout << "\n";
    }

    return 0;
}