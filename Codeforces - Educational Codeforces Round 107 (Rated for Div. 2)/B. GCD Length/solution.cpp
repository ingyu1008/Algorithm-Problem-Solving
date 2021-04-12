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

    ll p[10] = {0, 5, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};
    ll t[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    while (T--)
    {
        ll a, b, c;
        std::cin >> a >> b >> c;
        ll gcd = p[c];
        ll aa = gcd;
        ll bb = gcd;
        while (aa * 2 < t[a])
        {
            aa *= 2;
        }
        while (bb * 3 < t[b])
        {
            bb *= 3;
        }

        std::cout << aa << " " << bb << "\n";
    }

    return 0;
}