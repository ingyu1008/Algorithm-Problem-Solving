#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll x[10000001];
ll y[10000001];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    x[1] = 1;
    y[1] = 1;
    for (int i = 2; i <= 10000000; i++)
    {
        x[i] += i + 1;
        for (int j = i + i; j <= 10000000; j += i)
        {
            x[j] += i;
        }
        if (x[i] > 10000000)
            continue;
        if (y[x[i]] == 0)
            y[x[i]] = i;
    }

    int T;
    std::cin >> T;
    while (T--)
    {
        int c;
        std::cin >> c;
        if (y[c] == 0)
            std::cout << "-1\n";
        else
            std::cout << y[c] << "\n";
    }

    return 0;
}