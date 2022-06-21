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
#include <stack>

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

int map[101][101];
int N, M;
std::stack<std::pair<int, int>> st;

bool solve()
{
    bool end = true;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j])
                end = false;
        }
    }

    if (end)
        return false;

    // row
    for (int i = 1; i <= N; i++)
    {
        int select = 0;
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] > 0)
            {
                if (select == 0)
                {
                    select = map[i][j];
                }
                else if (map[i][j] != select)
                {
                    select = 0;
                    break;
                }
            }
        }

        if (select > 0)
        {
            st.push({i + N, select});
            for (int j = 1; j <= N; j++)
            {
                map[i][j] = 0;
            }
            return true;
        }
    }

    // column
    for (int i = 1; i <= N; i++)
    {
        int select = 0;
        for (int j = 1; j <= N; j++)
        {
            if (map[j][i] > 0)
            {
                if (select == 0)
                {
                    select = map[j][i];
                }
                else if (map[j][i] != select)
                {
                    select = 0;
                    break;
                }
            }
        }

        if (select > 0)
        {
            st.push({i, select});
            for (int j = 1; j <= N; j++)
            {
                map[j][i] = 0;
            }
            return true;
        }
    }

    return false;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
        }
    }

    bool more = true;

    while (more)
    {
        more = solve();
    }
    std::cout << st.size() << "\n";
    while (!st.empty())
    {
        auto p = st.top();
        st.pop();

        if (p.first > N)
        {
            std::cout << "H " << p.first - N << " " << p.second << "\n";
        }
        else
        {
            std::cout << "V " << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}