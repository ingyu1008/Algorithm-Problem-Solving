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

int R, C, N;
int grid[202][202];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void simulate(int t) {
    if ((t & 1) == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] < 0) grid[i][j] = t;
            }
        }
    } else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == t - 3) {
                    grid[i][j] = -1;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                            if (grid[nx][ny] == t - 1) {
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < C; j++) {
            if (row[j] == 'O') {
                grid[i][j] = 0;
            } else {
                grid[i][j] = -1;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        simulate(i);
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if (grid[i][j] >= 0) {
                std::cout << "O";
            }
            else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
