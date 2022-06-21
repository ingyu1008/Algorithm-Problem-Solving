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
        int N;
        std::cin >> N;

        std::vector<std::pair<int,int>> v(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i].first;
            v[i].second = i;
        }

        std::sort(v.begin(), v.end());

        if(v[0].first != v[1].first){
            std::cout << v[0].second + 1 << "\n";
        } else {
            std::cout << v[N-1].second + 1 << "\n";
        }
    }

    return 0;
}