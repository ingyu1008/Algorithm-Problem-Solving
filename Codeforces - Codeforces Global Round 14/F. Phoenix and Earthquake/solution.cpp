//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef long long ll;

ll N, M, X;
int par[303030];
ll total[303030];

std::vector<std::pair<int, int>> v[303030];
std::vector<int> ans;

void init()
{
    for (int i = 1; i <= 300000; i++)
    {
        par[i] = i;
    }
}

int find(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

ll get(int a)
{
    return total[find(a)];
}

void uni(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b)
    {
        par[a] = b;
        total[b] = total[a] + total[b] - X;
    }
}

void scan(int node)
{
    std::priority_queue<std::pair<ll, std::pair<int, int>>> pq;
    for (auto p : v[node])
    {
        int next = p.first;
        if (find(node) != find(next) && get(node) + get(next) >= X)
        {
            pq.push({get(next), {find(next), p.second}});
        }
    }

    while (!pq.empty())
    {
        int next = pq.top().second.first;
        int idx = pq.top().second.second;
        pq.pop();
        if (find(node) != find(next) && get(node) + get(next) >= X)
        {
            uni(node, next);
            ans.push_back(idx);
            for (auto p : v[next])
            {
                int nextnext = p.first;
                if (find(next) != find(nextnext) && get(next) + get(nextnext) >= X)
                {
                    pq.push({get(nextnext), {find(nextnext), p.second}});
                }
                v[nextnext].push_back({node, p.second});
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M >> X;
    init();

    std::priority_queue<std::pair<ll, int>> pq;
    std::priority_queue<std::pair<ll, int>> pq2;

    for (int i = 1; i <= N; i++)
    {
        std::cin >> total[i];
        pq.push({total[i], i});
    }

    for (int i = 1, x, y; i <= M; i++)
    {
        std::cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
    }

    while (!pq.empty())
    {
        int idx = pq.top().second;
        // std::cout << "\n"
        //           << idx << "\n";
        pq.pop();

        scan(idx);
        pq2.push({get(idx), idx});
    }

    while (!pq2.empty())
    {
        int idx = pq2.top().second;
        // std::cout << "\n"
        //           << idx << "\n";
        pq2.pop();

        scan(idx);
    }

    if (ans.size() >= N - 1)
    {
        std::cout << "YES\n";
        for (int i = 0; i < N - 1; i++)
        {
            std::cout << ans[i] << "\n";
        }
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}
