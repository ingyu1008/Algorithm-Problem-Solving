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

typedef unsigned long long ll;
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

std::set<ll> st;
std::set<ll> visited;

int map[64];
int N, K;

void solve(ll bitmask, int k)
{
    if (visited.find(bitmask) != visited.end())
        return;
    visited.insert(bitmask);
    if (k == 0)
    {
        st.insert(bitmask);
        return;
    }

    for (int i = 0; i < N * N; i++)
    {
        if (bitmask & (1LL << i) || map[i] == 1LL)
            continue;

        if ((i % N) > 0 && (bitmask & (1LL << (i - 1LL))))
        {
            solve(bitmask | (1LL << i), k - 1LL);
        }
        else if (i >= N && (bitmask & (1LL << (i - N))))
        {
            solve(bitmask | (1LL << i), k - 1LL);
        }
        else if (i < N * N - N && (bitmask & (1LL << (i + N))))
        {
            solve(bitmask | (1LL << i), k - 1LL);
        }
        else if ((i % N) < N - 1LL && (bitmask & (1LL << (i + 1LL))))
        {
            solve(bitmask | (1LL << i), k - 1LL);
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> K;

    std::string s;
    for (int i = 0; i < N; i++)
    {
        std::cin >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == '#')
                map[i * N + j] = 1LL;
        }
    }

    for (int i = 0; i < N * N; i++)
    {
        if (map[i] == 0)
            solve((1LL << i), K - 1LL);
    }
    std::cout << st.size() << "\n";

    return 0;
}