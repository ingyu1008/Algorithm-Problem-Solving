#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

std::set<int> st;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<bool> v(10, true);

    for (int i = 0, x; i < M; i++)
    {
        std::cin >> x;
        v[x] = false;
    }

    std::string x = "";
    for (int a = 0; a < 10; a++)
    {
        if (!v[a])
            continue;
        x.push_back('0' + a);
        st.insert(std::stoi(x));
        for (int b = 0; b < 10; b++)
        {
            if (!v[b])
                continue;
            x.push_back('0' + b);
            st.insert(std::stoi(x));
            for (int c = 0; c < 10; c++)
            {
                if (!v[c])
                    continue;
                x.push_back('0' + c);
                st.insert(std::stoi(x));
                for (int d = 0; d < 10; d++)
                {
                    if (!v[d])
                        continue;
                    x.push_back('0' + d);
                    st.insert(std::stoi(x));
                    for (int e = 0; e < 10; e++)
                    {
                        if (!v[e])
                            continue;
                        x.push_back('0' + e);
                        st.insert(std::stoi(x));
                        for (int f = 0; f < 10; f++)
                        {
                            if (!v[f])
                                continue;
                            x.push_back('0' + f);
                            st.insert(std::stoi(x));
                            if (x == "000000" && v[1])
                            {
                                st.insert(1000000);
                            }
                            x.pop_back();
                        }
                        x.pop_back();
                    }
                    x.pop_back();
                }
                x.pop_back();
            }
            x.pop_back();
        }
        x.pop_back();
    }

    int mn = abs(N - 100);

    for (int i : st)
    {
        mn = std::min(mn, abs(N - i) + (int)std::to_string(i).size());
    }
    std::cout << mn << "\n";

    return 0;
}