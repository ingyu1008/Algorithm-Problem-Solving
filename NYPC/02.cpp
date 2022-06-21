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

int start[100][100];
int end[100][100];
int count[100][100];
int cum[100][100];
int from[100][100];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            start[i][j] = 1e9;
            end[i][j] = 1e9;
            from[i][j] = -1;
        }
    }

    int nodeptr = 0;
    int startptr = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        nodeptr = 0;
        startptr = 0;
        cnt = 0;
        std::string s;
        std::cin >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'D')
            {
                cnt++;
            }

            if (s[j] == 'U')
            {
                start[i][nodeptr] = startptr;
                end[i][nodeptr] = j - 1;
                count[i][nodeptr] = cnt;
                cnt = 0;
                nodeptr++;
                startptr = j + 1;
            }
            else if (j == N - 1)
            {
                start[i][nodeptr] = startptr;
                end[i][nodeptr] = j;
                count[i][nodeptr] = cnt;
                cnt = 0;
                nodeptr++;
                startptr = j + 1;
            }
        }
    }

    cum[0][0] = count[0][0]+100;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if ((i > 0 || j == 0) && start[i][j] <= end[i][j] && (end[i][j] >= start[i + 1][k] && end[i + 1][k] >= start[i][j]) && start[i + 1][k] <= end[i + 1][k])
                {
                    if (count[i + 1][k] + cum[i][j] > cum[i + 1][k])
                    {
                        cum[i + 1][k] = count[i + 1][k] + cum[i][j];
                        from[i + 1][k] = j;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << cum[i][j] << " ";
        }
        std::cout << "\n";
    }

    int j = 0;
    for (;; j++)
    {
        if (start[N - 1][j] <= N - 1 && end[N - 1][j] >= N - 1)
        {
            break;
        }
    }

    std::cout << cum[N - 1][j] << "\n";

    for (int i = N - 1; i > 0; i--)
    {
        if (i % 3 == 0)
            std::cout << "\n";
        std::cout << from[i][j] << " ";
        j = from[i][j];
    }

    return 0;
}