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

    int N;
    std::cin >> N;

    for (int h = 1; h < 10; h++) {
        for (int e = 0; e < 10; e++) {
            if (h == e) continue;
            for (int l = 0; l < 10; l++) {
                if (l == e || l == h) continue;
                for (int o = 0; o < 10; o++) {
                    if (o == l || o == e || o == h) continue;
                    for (int w = 1; w < 10; w++) {
                        if (w == o || w == l || w == e || w == h) continue;
                        for (int r = 0; r < 10; r++) {
                            if (r == w || r == o || r == l || r == e || r == h) continue;
                            for (int d = 0; d < 10; d++) {
                                if (d == r || d == w || d == o || d == l || d == e || d == h) continue;
                                int nn = N;
                                int cnt = 0;
                                while (nn) {
                                    cnt++;
                                    nn /= 10;
                                }
                                int spcnt = std::max(cnt, 7);
                                if ((h + w) * 10000 + (e + o) * 1000 + (l + r) * 100 + (l + l) * 10 + (o + d) * 1 == N) {
                                    for (int sp = 0; sp + 5 < spcnt; sp++) std::cout << " ";
                                    std::cout << h << e << l << l << o << "\n+";
                                    for (int sp = 0; sp + 6 < spcnt; sp++) std::cout << " ";
                                    std::cout << w << o << r << l << d << "\n";
                                    for (int sp = 0; sp < spcnt; sp++) std::cout << "-";
                                    std::cout << "\n";
                                    for (int sp = 0; sp + cnt < spcnt; sp++) std::cout << " ";
                                    std::cout << N << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "No Answer\n";

    return 0;
}
