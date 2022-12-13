//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
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

        std::vector<int> v(N);

        for(int i = 0; i < N; i++){
            std::cin >> v[i];
        }

        int idx = 0;
        while(K--){
            while(idx < N && v[idx] == 0){
                idx++;
            }
            if(idx >= N-1)break;

            v[idx]--;
            v[N-1]++;
        }

        for(int i = 0; i < N;i++){
            std::cout << v[i] << " ";
        }

        std::cout << "\n";
    }

    return 0;
}

