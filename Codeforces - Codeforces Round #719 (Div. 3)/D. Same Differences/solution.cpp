//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        std::map<int,int> mp;

        int N;
        std::cin >> N;
        long long ans = 0;
        for(int i = 0,x; i < N;i++){
            std::cin >> x;
            x -= i;
            ans += mp[x];
            mp[x]++;
        }
        std::cout << ans << "\n";
    }

    return 0;
}
