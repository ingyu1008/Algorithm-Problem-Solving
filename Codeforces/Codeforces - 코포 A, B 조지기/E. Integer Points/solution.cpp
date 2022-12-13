#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M;
        ll po = 0, pe = 0, qo = 0, qe = 0;
        std::cin >> N;
        int x;
        for (int i = 0; i < N; i++)
        {
            std::cin >> x;
            if (x & 1)
                po++;
            else
                pe++;
        }

        std::cin >> M;
        for (int i = 0; i < M; i++)
        {
            std::cin >> x;
            if (x & 1)
                qo++;
            else
                qe++;
        }

        std::cout << po * qo + pe * qe << "\n";
    }

    return 0;
}