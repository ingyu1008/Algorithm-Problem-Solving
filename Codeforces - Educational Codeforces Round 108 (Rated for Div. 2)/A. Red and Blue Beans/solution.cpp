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
    while (T--){
        ll r, b, d;
        std::cin >> r >> b >> d;

        if(r > b){
            std::swap(r, b);
        }    

        if(r*(d+1) >= b){
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
