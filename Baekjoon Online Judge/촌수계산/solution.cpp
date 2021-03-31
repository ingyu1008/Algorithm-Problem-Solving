#include <iostream>
#include <vector>
#include <algorithm>

int v[111][111];
bool visited[111];

int dfs(int from, int to)
{
    if (from == to)
        return 0;
    if (visited[from])
        return 10000;
    visited[from] = true;

    int ret = 10000;
    for (int next = 1; next <= 100; next++)
    {
        if (visited[next])
            continue;
        if (!v[from][next])
            continue;
        ret = std::min(ret, dfs(next, to) + 1);
    }
    return ret;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int from, to;
    std::cin >> from >> to;

    int M;
    std::cin >> M;

    int x, y;
    for (int i = 0; i < M; i++)
    {
        std::cin >> x >> y;
        v[x][y] = 1;
        v[y][x] = 1;
    }

    int res = dfs(from, to);

    std::cout << ((res < 10000) ? res : -1) << "\n";

    return 0;
}