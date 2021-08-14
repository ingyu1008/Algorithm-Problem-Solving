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

ll mod = 1e6;

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

int db[17] = {
    1 + 2 + 8 + 16,   // 정사각형
    1 + 2 + 4 + 8,    // s 블럭 - 1
    1 + 8 + 16 + 128, // s 블럭 - 2
    1 + 2 + 16 + 32,  // z 블럭 - 1
    1 + 4 + 8 + 32,   // z 블럭 - 2
    1 + 2 + 4 + 16,   // t 블럭 - 1
    1 + 4 + 8 + 64,   // t 블럭 - 2
    1 + 8 + 16 + 64,  // t 블럭 - 3
    1 + 4 + 8 + 16,   // t 블럭 - 4
    1 + 2 + 4 + 8,    // L 블럭 - 1
    1 + 8 + 64 + 128, // L 블럭 - 2
    1 + 2 + 16 + 128, // L 블럭 - 3
    1 + 2 + 4 + 8,    // L 블럭 - 4
    1 + 2 + 4 + 32,   // ㄱ 블럭 - 1
    1 + 8 + 32 + 64,  // ㄱ 블럭 - 2
    1 + 8 + 16 + 32,  // ㄱ 블럭 - 3
    1 + 2 + 8 + 64    // ㄱ 블럭 - 4
};
int possible[17][3] = {
    {1, 1, 0},
    {0, 1, 0},
    {1, 1, 0},
    {1, 0, 0},
    {0, 1, 1},
    {1, 0, 0},
    {0, 1, 1},
    {1, 1, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 0},
    {0, 0, 1},
    {1, 0, 0},
    {0, 1, 1},
    {1, 0, 0},
    {1, 1, 0}};

int N;

ll dp[1212][256];

// 3 * n 쌓는 경우의수
// n : 남은 칸의 수
// bitmask : 현재 보고있는 칸 포함 다음 8개의 정보 0 ~ 2^9 -1
ll solve(ll n, ll bitmask)
{
    // std::cout << n << " " << bitmask << "\n";
    if(dp[n][bitmask] >= 0) return dp[n][bitmask];
    if (n == 3 * N)
        return dp[n][bitmask] = (bitmask == 0);
    if ((bitmask & 1) == 1)
        return dp[n][bitmask] = solve(n + 1, bitmask >> 1);

    ll sum = 0;

    for (int i = 0; i < 17; i++)
    {
        if (possible[i][(n + 3) % 3] == 1 && (bitmask & db[i]) == 0)
        {
            sum = (sum + solve(n + 1, (bitmask | db[i]) >> 1)) % mod;
        }
    }

    return dp[n][bitmask] = sum;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    for(int i = 0; i <= 1200; i++){
        for(int j = 0; j < 256; j++){
            dp[i][j] = -1;
        }
    }

    std::cin >> N;

    std::cout << solve(0, 0);

    return 0;
}
