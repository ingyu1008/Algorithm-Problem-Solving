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
#include <queue>

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

    int N;
    std::cin >> N;
    std::string s = "0";
    for (int i = 0; i < N; i++)
    {
        s = "1" + s + "2";
    }

    std::queue<std::pair<int, int>> q;
    int x = 2;

    for (int j = 0; j < 2 * N + 1; j++)
    {
        int one = 0;
        int two = 0;

        for (int i = 0; i < 2 * N + 1; i++)
        {
            one += (s[i] == '1');
            two += (s[i] == '2');
            if (s[i] - '0' != x || i == 0)
            {
                continue;
            }
            if (i == 1)
            {
                if (s[i - 1] == '0')
                {
                    q.push({s[i] - '0', s[i] == '1' ? one : two});
                    std::swap(s[i - 1], s[i]);
                }
            }
            else
            {
                if (s[i - 1] == '0' && (j >= N || s[i - 2] != s[i]))
                {
                    q.push({s[i] - '0', s[i] == '1' ? one : two});
                    std::swap(s[i - 1], s[i]);
                }
                else if (s[i - 2] == '0' && (j >= N || s[i - 1] != s[i]))
                {
                    q.push({s[i] - '0', s[i] == '1' ? one : two});
                    std::swap(s[i - 2], s[i]);
                }
            }
        }
        std::reverse(s.begin(), s.end());
        x ^= 3;
    }

    std::cout << q.size() << "\n";

    while (!q.empty())
    {
        std::cout << q.front().first << " " << q.front().second << "\n";
        q.pop();
    }

    return 0;
}