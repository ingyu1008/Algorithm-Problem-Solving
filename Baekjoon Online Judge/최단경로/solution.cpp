//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int V, E;
    std::cin >> V >> E;

    int start;
    std::cin >> start;

    std::vector<std::pair<int, int>> v[20202];
    for (int i = 0, x, y, z; i < E; i++)
    {
        std::cin >> x >> y >> z;
        v[x].push_back({y, z});
    }

    std::vector<int> dist(V + 1);

    for (int i = 0; i <= V; i++)
    {
        dist[i] = 1e9 + 7;
    }
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > dist[now])
            continue;

        for (auto p : v[now])
        {
            int next = cost + p.second;
            if (dist[p.first] > next)
            {
                dist[p.first] = next;
                pq.push({-next, p.first});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == 1e9 + 7)
        {
            std::cout << "INF\n";
        }
        else
        {
            std::cout << dist[i] << "\n";
        }
    }

    return 0;
}
