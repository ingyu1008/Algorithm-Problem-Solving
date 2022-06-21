#include <iostream>
#include <sstream>

int state[2][3];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::stringstream ss("123");
    int a;
    ss >> a;

    std::cout << a << "\n";

    return 0;
}