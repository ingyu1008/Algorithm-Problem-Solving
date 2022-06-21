#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>

std::set<int> st;
std::set<int> sets[505];
std::vector<int> v[505];
std::vector<int> rv[505];
std::vector<std::pair<int, std::pair<int, int>>> v2[505];
bool visited[505];
bool visited2[505];
int N, M, K;

void dfs(int node)
{
    for (auto x : st)
    {
        sets[node].insert(x);
    }
    st.insert(node);
    for (auto x : v[node])
    {
        dfs(x);
    }
    st.erase(node);
}

bool dfs2(int bitmask) // from http://boj.kr/12f2d70256924a9bb1dc9461052d9b41 code by ingyu1008(me)
{
    std::stack<int> s, st;
    for (int i = N; i > 0; i--)
    {
        s.push(i);
    }

    while (!s.empty())
    {
        int pos = s.top();
        s.pop();
        if (visited[pos])
        {
            if (!visited2[pos])
            {
                st.push(pos);
                visited2[pos] = true;
            }
            continue;
        }
        visited[pos] = true;
        s.push(pos);
        for (auto it = v[pos].begin(); it != v[pos].end(); it++)
        {
            s.push(*it);
        }
        for (auto p : v2[pos])
        {
            if ((p.second.first == pos) && (((1 << (K - 1 - p.first)) & bitmask) == 0))
            {
                s.push(p.second.second);
            }
            else if ((p.second.second == pos) && (((1 << (K - 1 - p.first)) & bitmask) == 1))
            {
                s.push(p.second.first);
            }
        }
    }

    std::vector<std::vector<int>> vv;
    std::vector<int> vvv;
    std::fill_n(visited, 505, false);

    while (!st.empty())
    {
        s.push(st.top());
        st.pop();
        while (!s.empty())
        {
            int pos = s.top();
            s.pop();
            if (visited[pos])
                continue;
            visited[pos] = true;
            vvv.push_back(pos);
            for (auto it = rv[pos].begin(); it != rv[pos].end(); it++)
            {
                s.push(*it);
            }

            for (auto p : v2[pos])
            {
                if (p.second.first == pos && (((1 << (K - 1 - p.first)) & bitmask) == 1))
                {
                    s.push(p.second.second);
                }
                else if (p.second.second == pos && (((1 << (K - 1 - p.first)) & bitmask) == 0))
                {
                    s.push(p.second.first);
                }
            }
        }
        if (vvv.size())
        {
            vv.push_back(vvv);
            vvv.clear();
        }
    }

    return (vv.size() == N);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i < 505; i++)
        {
            sets[i].clear();
            v[i].clear();
            rv[i].clear();
            v2[i].clear();
        }
        st.clear();

        std::cout << "Case #" << t << "\n";
        std::cin >> N >> M >> K;

        std::vector<int> in(505);
        std::vector<int> order(505);
        std::vector<int> ans(K);

        for (int i = 0, a, b; i < M; i++)
        {
            std::cin >> a >> b;
            v[a].push_back(b);
            rv[b].push_back(a);
            in[b]++;
        }

        std::queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (in[i] == 0)
            {
                q.push(i);
            }
        }

        for (int i = 0; !q.empty(); i++)
        {
            int node = q.front();
            order[node] = i;
            for (auto x : v[node])
            {
                in[x]--;
                if (in[x] == 0)
                {
                    q.push(x);
                }
            }
            q.pop();
        }
        for (int i = 1; i <= N; i++)
        {
            dfs(i);
        }

        if (N > 10)
        {
            for (int i = 0, a, b; i < K; i++)
            {
                std::cin >> a >> b;
                if (order[a] < order[b])
                    ans[i] = 0;
                else if (sets[a].find(b) == sets[a].end())
                {
                    v[a].push_back(b);
                    for (auto x : sets[a])
                    {
                        st.insert(x);
                    }
                    dfs(a);
                    st.clear();
                    ans[i] = 0;
                }
                else
                    ans[i] = 1;
            }
        }
        else
        {
            for (int i = 0, a, b; i < K; i++)
            {
                std::cin >> a >> b;
                v2[a].push_back({i, {a, b}});
                v2[b].push_back({i, {a, b}});
            }
            for (int i = 0; i < (1 << K); i++)
            {
                for (int j = 0; j < K; j++)
                {
                    ans[(K - 1) - j] = ((i & (1 << j)) ? 1 : 0);
                }

                for (int j = 0; j <= N; j++)
                {
                    visited[j] = false;
                    visited2[j] = false;
                }
                if (dfs2(i))
                    break;
            }
        }

        for (int i = 0; i < K; i++)
        {
            std::cout << ans[i];
        }
        std::cout << "\n";
    }

    return 0;
}