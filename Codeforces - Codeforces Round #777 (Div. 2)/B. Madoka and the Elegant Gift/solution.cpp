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

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N >> M;

        bool flag = false;

        std::vector<std::string> v(N);
        for (int i = 0; i < N; ++i)
            std::cin >> v[i];

        std::vector<std::vector<int>> sum(N, std::vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                sum[i][j] = (j == 0 ? v[i][j] - '0' : sum[i][j-1] + v[i][j] - '0');

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j] == '0') continue;

                int ii = i, jj = j;
                while (ii < N - 1 && v[ii + 1][jj] == '1') {
                    ii++;
                }

                while (jj < M - 1 && sum[ii][jj + 1] - sum[ii][j] == jj - j + 1) {
                    jj++;
                    if (ii < N - 1 && v[ii + 1][jj] == '1') {
                        flag = true;
                    }
                }
                if (jj < M - 1) {
                    for (int k = i; k <= ii; k++) {
                        if (v[k][jj + 1] == '1') {
                            flag = true;
                        }
                    }
                }
            }
        }

        if (flag) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    }

    return 0;
}
