//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::set<long long> s;
    for (long long i = 1; i * i <= 1e9; i++)
    {
        s.insert(i*i*2);
        s.insert(i*i*4);
    }

    int T;
    std::cin >> T;
    while (T--)
    {
        long long N;
        std::cin >> N;

        std::cout << ((s.find(N) == s.end())?"NO\n":"YES\n");
    }

    return 0;
}
