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

    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> day(K);
    std::vector<std::pair<int, int>> worker(N);
    std::vector<int> workers[K + 1];

    for (int i = 0; i < N; i++)
    {
        std::cin >> worker[i].first;
        worker[i].second = i + 1;
    }

    for (int i = 0; i < K; i++)
    {
        std::cin >> day[i].first;
        day[i].second = i + 1;
    }

    std::sort(day.rbegin(), day.rend());
    std::sort(worker.rbegin(), worker.rend());

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < worker[i].first; j++)
        {
            day[j].first--;
            workers[day[j].second].push_back(worker[i].second);
        }
        std::sort(day.rbegin(), day.rend());
    }

    for (int i = 1; i <= K; i++)
    {
        std::cout << workers[i].size() << " ";
        for (int x : workers[i])
        {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }

    return 0;
}