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

    int arr[50];
    int arr2[50];

    for (int n = 1; n <= 8; n++)
    {
        arr[n-1] = n;
        arr2[n-1] = n;
        int ans = 0;

        do
        {
            do
            {

                int cnt = 0;
                int cnt2 = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if (arr[i] > arr[j])
                            cnt++;
                        if (arr2[i] > arr2[j])
                            cnt2++;
                    }
                }
                if (cnt > cnt2)
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (arr[i] < arr2[i])
                            goto count;
                        if (arr[i] > arr2[i])
                            goto next;
                    }

                count:
                    ans++;
                next:
                    continue;
                }
            } while (std::next_permutation(arr2, arr2 + n));
        } while (std::next_permutation(arr, arr + n));

        std::cout << ans << "\n";
    }

    return 0;
}
