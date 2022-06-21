#include <iostream>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    int X, Y;
    std::cin >> X >> Y;

    int ans = 0;
    while( X < Y ){
        X += 10;
        ans++;
    }
    std::cout << ans << "\n";
    
    return 0;
}