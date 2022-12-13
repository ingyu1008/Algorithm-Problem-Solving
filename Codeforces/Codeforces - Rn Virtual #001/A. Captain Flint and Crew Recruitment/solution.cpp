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

        //2 3 5 7
        //6 10 14 15 21

        N -= 6+10+14;

        if(N > 0 && N != 6 && N != 10 && N !=14){
            std::cout << "YES\n6 10 14 " << N << "\n";
            continue;
        }
        N--;
        if(N > 0 && N != 6 && N != 10 && N !=15){
            std::cout << "YES\n6 10 15 " << N << "\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}