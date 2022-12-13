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
        int N;
        std::cin >> N;

        ll sum = 0;

        std::vector<int> v(N + 2);
        for (int i = 0; i < N + 2; i++)
        {
            std::cin >> v[i];
            sum += v[i];
        }
        std::sort(v.begin(), v.end());

        bool found = false;

        for (int i = 0; !found && i < N + 2; i++)
        {
            ll remain = sum - v[i];
            if (remain & 1)
                continue;
            auto it = std::lower_bound(v.begin(), v.end(), remain / 2);
            if (it == v.end())
                continue;
            if (it - v.begin() == i)
            {
                it++;
            }
            if (it == v.end())
                continue;
            if (*it != remain / 2)
                continue;
            found = true;
            for (int j = 0; j < N + 2; j++)
            {
                if (j == i)
                    continue;
                if (j == it - v.begin())
                    continue;
                std::cout << v[j] << " ";
            }
        }
        if (found)
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}