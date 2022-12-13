#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string s;

    std::cin >> s;

    int a = 0;
    int b, c;

    bool fib = true;

    for (int i = 2; i < s.size(); i++)
    {
        if ((s[i - 2] - 'A' + s[i - 1] - 'A') % 26 != s[i] - 'A')
        {
            fib = false;
        }
    }

    std::cout << ((fib) ? "YES\n" : "NO\n");

    return 0;
}