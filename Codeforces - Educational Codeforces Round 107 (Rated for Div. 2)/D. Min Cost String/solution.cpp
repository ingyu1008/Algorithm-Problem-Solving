#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, K;
    std::cin >> N >> K;
    while (N)
    {
        for (char i = 'a'; N > 0 && i < 'a' + K; i++)
        {
            for (char j = i; N > 0 && j < 'a' + K; j++)
            {
                std::cout << i;
                N--;
                if (i != j && N > 0)
                {
                    std::cout << j;
                    N--;
                }
            }
        }
    }

    return 0;
}