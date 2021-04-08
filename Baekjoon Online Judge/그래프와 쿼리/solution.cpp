#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

std::vector<int> w[1010];
std::vector<std::pair<int, int>> edges;
std::stack<std::pair<std::string, int>> query;
std::stack<int> ans;
std::vector<int> dist(1010, 200000);

void dfs(int node)
{
    for (int next : w[node])
    {
        if (dist[next] > dist[node] + 1)
        {
            dist[next] = dist[node] + 1;
            dfs(next);
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M, Q;

    std::cin >> N >> M >> Q;

    std::set<int> st;
    for (int i = 0, u, v; i < M; i++)
    {
        std::cin >> u >> v;
        edges.push_back({u, v});
        st.insert(i);
    }

    {
        std::string t;
        for (int i = 0, p; i < Q; i++)
        {
            std::cin >> t >> p;
            if (t == "U")
            {
                p--;
                st.erase(p);
            }
            query.push({t, p});
        }
    }

    for (int idx : st)
    {
        int u = edges[idx].first;
        int v = edges[idx].second;
        w[u].push_back(v);
    }

    dist[1] = 0;
    dfs(1);

    while (!query.empty())
    {
        std::string t = query.top().first;
        int p = query.top().second;
        query.pop();

        if (t == "U")
        {
            int u = edges[p].first;
            int v = edges[p].second;
            w[u].push_back(v);
            dfs(u);
            dfs(v);
        }
        else
        {
            if (dist[p] < 200000)
            {
                ans.push(dist[p]);
            }
            else
            {
                ans.push(-1);
            }
        }
    }

    while (!ans.empty())
    {
        std::cout << ans.top() << "\n";
        ans.pop();
    }

    return 0;
}