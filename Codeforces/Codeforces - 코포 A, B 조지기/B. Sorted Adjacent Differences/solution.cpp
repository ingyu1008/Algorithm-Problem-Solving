#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

        std::vector<int> v(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
        }

        std::sort(v.begin(), v.end());

        std::stack<int> s;

        for (int l = 0, r = N - 1; l <= r; l++, r--)
        {
            if (l != r)
            {
                s.push(v[l]);
            }
            s.push(v[r]);
        }

        while (!s.empty())
        {
            std::cout << s.top() << " ";
            s.pop();
        }

        std::cout << "\n";
    }

    return 0;
}