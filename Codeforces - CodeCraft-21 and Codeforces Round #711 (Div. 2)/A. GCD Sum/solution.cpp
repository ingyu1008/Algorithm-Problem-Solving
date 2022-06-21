#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (a > b)
        return gcd(b, a);
    while (a)
        a ^= b ^= a ^= b %= a;
    return b;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        ll n;
        std::cin >> n;

        while (true)
        {
            ll x = 0;
            ll y = n;
            while (y)
            {
                x += y % 10;
                y /= 10;
            }
            if (gcd(n, x) > 1)
            {
                std::cout << n << "\n";
                break; 
            }
            n++;
        }
    }

    return 0;
}