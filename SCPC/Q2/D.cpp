#include <iostream>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    int T;
    std::cin >> T;

    for(int t = 1; t <= T; t++){
        std::cout << "Case #" << t << "\n";
    }
    
    return 0;
}