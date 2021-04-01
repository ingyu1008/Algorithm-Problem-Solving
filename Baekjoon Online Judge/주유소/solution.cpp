#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll mn = 2147483647;

    int N;
    std::cin >> N;

    std::vector<ll> len(N);
    ll x;

    for (int i = 1; i < N; i++)
    {
        std::cin >> len[i];
    }

    ll res = 0;

    std::cin >> mn;

    for (int i = 1; i < N; i++)
    {
        res += mn * len[i];
        std::cin >> x;
        mn = std::min(mn, x);
    }

    std::cout << res << "\n";

    return 0;
}