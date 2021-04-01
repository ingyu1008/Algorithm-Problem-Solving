#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string s;
    std::cin >> s;
    int x = s[s.size() - 1] - '0';

    std::cout << (x&1) << "\n";

    return 0;
}