#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, l, r, s;
        std::cin >> N >> l >> r >> s;
        l--, r--;

        int mn = (r - l + 1) * (r - l + 2) / 2;
        int mx = (r - l + 1) * (N + (N - (r - l))) / 2;

        if (mn > s || mx < s)
            std::cout << "-1\n";
        else
        {
            std::vector<int> v(N);
            s -= mn;
            std::set<int> st;
            for (int i = l; i <= r; i++)
            {
                v[i] = i - l + 1;
            }
            for (int i = r; i >= l; i--)
            {
                while (s > 0 && v[i] < N - (r - i))
                {
                    s--;
                    v[i]++;
                }
                st.insert(v[i]);
            }
            for (int i = 0, j = 1; i < N; i++)
            {
                while (st.find(j) != st.end())
                    j++;
                if (v[i] == 0)
                {
                    std::cout << j << " ";
                    st.insert(j);
                }
                else
                {
                    std::cout << v[i] << " ";
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}