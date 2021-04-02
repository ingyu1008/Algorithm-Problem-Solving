#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    std::set<int> st;

    bool valid = true;

    while (a)
    {
        if (st.find(a % b) != st.end())
        {
            std::cout << "NO";
            return 0;
        }
        st.insert(a % b);
        a /= b;
    }

    std::cout << "YES";

    return 0;
}