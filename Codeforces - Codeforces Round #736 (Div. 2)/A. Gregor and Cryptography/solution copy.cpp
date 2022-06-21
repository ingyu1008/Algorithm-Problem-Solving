/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <random>
#include <ctime>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<pii> vpii;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
        b = (b * a) % mod;
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        a ^= b ^= a ^= b;
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

/********************************************************************
						End Of Template
********************************************************************/

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    srand(time(NULL));

    int tc = 40;
    int mx = 0;
    int mxP = 0;

    int p[40] = {90000301 , 90000331 , 90000343 , 90000373 , 90000377 , 90000401 , 90000433 , 90000439 , 90000451 , 90000461 , 90000479 , 90000551 , 90000553 , 90000571 , 90000583 , 90000607 , 90000611 , 90000653 , 90000667 , 90000683};
    while (tc--)
    {
        int P = p[tc];
        for (int i = 3; i < P; i++)
        {
            if (P % i == 1)
            {
                if (i > mx)
                {
                    mx = i;
                    mxP = P;
                }
                break;
            }
        }
    }

    std::cout << mx << " " << mxP << "\n";

    return 0;
}
