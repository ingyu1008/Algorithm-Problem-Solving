#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;
    while (Q--)
    {
        std::vector<std::vector<int>> v;
        int N;
        std::cin >> N;
        std::vector<int> vv(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> vv[i];
        }

        std::sort(vv.begin(), vv.end());

        for (int i = 0; i < N; i++)
        {
            bool newTeam = true;
            int z = vv[i];
            for (int j = 0; j < v.size(); j++)
            {
                std::vector<int> &x = v[j];
                bool here = true;
                for (int y : x)
                {
                    if (abs(y - z) == 1)
                    {
                        here = false;
                    }
                }
                if (here)
                {
                    newTeam = false;
                    x.push_back(z);
                    break;
                }
            }
            if (newTeam)
            {
                std::vector<int> temp;
                temp.push_back(z);
                v.push_back(temp);
            }
        }

        std::cout << v.size() << "\n";
    }

    return 0;
}