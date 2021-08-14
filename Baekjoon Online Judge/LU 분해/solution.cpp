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

double L[1001][1001];
double U[1001][1001];
double A[1001][1001];

bool recursive(int n, int mx)
{
    if (n > mx)
        return true;

    L[n][n] = 1;
    U[n][n] = A[n][n] - A[n - 1][n] * L[n][n - 1];
    U[n][n + 1] = A[n][n + 1] - A[n - 1][n + 1] * L[n][n - 1];
    L[n + 1][n] = A[n + 1][n] / U[n][n];

    if (U[n][n] == 0)
        return false;

    return recursive(n + 1, mx);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cout.precision(3);
    std::cout << std::fixed;

    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> A[i][j];
        }
    }

    if (recursive(1, N))
    {

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                std::cout << L[i][j] << " ";
            }
            std::cout << "\n";
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                std::cout << U[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
    else
    {
        std::cout << "-1\n";
    }

    return 0;
}
