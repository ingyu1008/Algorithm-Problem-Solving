#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int a;
    std::cin >> a;

    for(int i = 2; i*i <= a; i++){
        if(a%i == 0){
            std::cout << i << a/i << "\n";
            break;
        }
    }

    return 0;
}