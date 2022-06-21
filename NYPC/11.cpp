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

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int map[25][25];
int N, M;
bool visited[25][25][100001];
int par[25][25][100001];

bool isValid(int r, int c)
{
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
char dd[4] = {'D', 'U', 'R', 'L'};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;

    std::string input;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            map[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        for (int j = 0; j < M; j++)
        {
            if (input[j] == '.')
                continue;
            else if (input[j] == '#')
            {
                map[i][j] = 100002;
            }
            else
            {
                int X = input[j] - '0';
                map[i][j] = 100002;
                for (int dir = 0; dir < 4; dir++)
                {
                    int ii = i + dr[dir];
                    int jj = j + dc[dir];
                    if (!isValid(ii, jj))
                        continue;
                    map[ii][jj] = lcm(map[ii][jj], X);
                }
            }
        }
    }

    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
    pq.push({0, {0, 0}});

    int ans = 1e9;

    while (!pq.empty())
    {
        int t = -pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if (r == N - 1 && c == M - 1)
        {
            ans = std::min(ans, t);
        }
        if (t > 100000)
            continue;
        if (visited[r][c][t])
            continue;

        visited[r][c][t] = true;
        for (int dir = 0; dir < 4; dir++)
        {
            int rr = r + dr[dir];
            int cc = c + dc[dir];
            if (!isValid(rr, cc) || visited[rr][cc][t + 1] || (t + 1) % map[rr][cc] > 0)
                continue;
            par[rr][cc][t + 1] = dir;
            pq.push({-t - 1, {rr, cc}});
        }
    }

    std::stack<char> st;

    int r = N - 1;
    int c = M - 1;

    while (ans)
    {
        int dir = par[r][c][ans];
        st.push(dd[dir]);
        r -= dr[dir];
        c -= dc[dir];
        ans--;
    }

    while(!st.empty()){
        std::cout << st.top();
        st.pop();
    }

    return 0;
}