//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--) 
    {
        ll N;
        std::cin >> N;

        int cnt = 0;

        for(int i = 1; i <= 9; i++){
            std::string x = "0";
            x[0] += i;

            std::string y = x;

            while(std::stoll(y) <= N){
                cnt++;
                y += x;
            }
        }

        std::cout << cnt << "\n";
    }

    return 0;
}
