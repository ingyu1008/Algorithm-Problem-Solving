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

int cnt[100000] = {
    0,
};
int sum[100000] = {
    0,
};

struct Line
{
    int x;
    int y;
    int length;
    int diff;
};

void update(int node, int low, int high, int y, int length, int diff)
{
    if (high < y || low > y + length)
    {
        return;
    }
    if (low >= y && high <= y + length)
    {
        cnt[node] += diff;
    }
    else
    {
        int mid = (low + high) / 2;
        update(node * 2, low, mid, y, length, diff);
        update(node * 2 + 1, mid + 1, high, y, length, diff);
    }

    if (cnt[node] > 0)
    {
        sum[node] = high - low + 1;
    }
    else if (low < high)
    {
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
    }
    else
    {
        sum[node] = 0;
    }
}

struct Comparator
{
    bool operator()(Line o1, Line o2)
    {
        return o1.x > o2.x;
    }
};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 0, M, x1, x2, y1, y2; i < N; i++)
    {
        std::cin >> M >> x1 >> y1 >> x2 >> y2;

        if (y1 == y2)
        {
            
            for (int j = 2; j < M; j++)
            {
            }
        }
    }

    return 0;
}
