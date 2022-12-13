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
        int N, K;
        std::cin >> N >> K;
        int mx = (N-1)/2;
        if(mx < K){
            std::cout << -1 << "\n";
        } else {
            int l = 1;
            int r = N;
            while(K--){
                std::cout << l << " ";
                std::cout << r << " ";
                l++;
                r--;
            }
            while(l <= r){
                std::cout << l << " ";
                l++;
            }
            std::cout << "\n";
        }
    }

    return 0;
}