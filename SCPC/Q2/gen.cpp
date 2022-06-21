#include "testlib.h"
#include <iostream>

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int T = std::stoi(argv[1]);

    std::cout << T << "\n";

    while (T--)
    {
        std::cout << rnd.next(1, 5) << "\n";
        for (int i = 0; i < 8; i++)
        {
            std::cout << rnd.next(1, 20) << " " << rnd.next(1,20) << "\n";
        }
    }

    return 0;
}