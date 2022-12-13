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
        int cnt = 0;
        int N;
        std::cin >> N;
        while(N--){
            int c;
            std::cin >> c;
            cnt += 1 - (c==2);
        }
        std::cout << cnt << "\n";
    }

    return 0;
}