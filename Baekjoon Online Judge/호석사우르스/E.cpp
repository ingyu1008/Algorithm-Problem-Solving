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

ll zido[100][100];
ll visited[100][100][3];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    int Sx, Sy, Ex, Ey;
    std::cin >> Sx >> Sy >> Ex >> Ey;

    Sx--, Sy--, Ex--, Ey--;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> zido[i][j];
            visited[i][j][0] = mod;
            visited[i][j][1] = mod;
            visited[i][j][2] = mod;
        }
    }

    std::priority_queue<std::pair<ll, std::pair<std::pair<ll, ll>, ll>>> pq;

    visited[Sx][Sy][1] = 0;
    pq.push({0, {{Sx, Sy}, 1}});

    while (!pq.empty())
    {
        ll dist = -pq.top().first;
        ll x = pq.top().second.first.first;
        ll y = pq.top().second.first.second;
        ll state = pq.top().second.second;

        pq.pop();
        if (x == Ex && y == Ey)
        {
            std::cout << dist << "\n";
            return 0;
        }
        // if (visited[x][y][state] < dist)
        //     continue;

        if (x == Ex && y == Ey)
        {
            std::cout << dist << "\n";
            break;
        }

        if ((state % 3) == 1 || (state % 3) == 0) //상하
        {
            if (x + 1 < N)
            {
                if (visited[x + 1][y][(state + 1) % 3] > dist + zido[x + 1][y] && zido[x + 1][y] >= 0)
                {
                    visited[x + 1][y][(state + 1) % 3] = dist + zido[x + 1][y];
                    pq.push({-(dist + zido[x + 1][y]), {{x + 1, y}, state + 1}});
                }
            }
            if (x - 1 >= 0)
            {
                if (visited[x - 1][y][(state + 1) % 3] > dist + zido[x - 1][y] && zido[x - 1][y] >= 0)
                {
                    visited[x - 1][y][(state + 1) % 3] = dist + zido[x - 1][y];
                    pq.push({-(dist + zido[x - 1][y]), {{x - 1, y}, state + 1}});
                }
            }
        }

        if ((state % 3) == 2 || (state % 3) == 0) //좌우
        {
            if (y + 1 < M)
            {
                if (visited[x][y + 1][(state + 1) % 3] > dist + zido[x][y + 1] && zido[x][y + 1] >= 0)
                {
                    visited[x][y + 1][(state + 1) % 3] = dist + zido[x][y + 1];
                    pq.push({-(dist + zido[x][y + 1]), {{x, y + 1}, state + 1}});
                }
            }
            if (y - 1 >= 0)
            {
                if (visited[x][y - 1][(state + 1) % 3] > dist + zido[x][y - 1] && zido[x][y - 1] >= 0)
                {
                    visited[x][y - 1][(state + 1) % 3] = dist + zido[x][y - 1];
                    pq.push({-(dist + zido[x][y - 1]), {{x, y - 1}, state + 1}});
                }
            }
        }
    }

    std::cout << -1;

    return 0;
}
