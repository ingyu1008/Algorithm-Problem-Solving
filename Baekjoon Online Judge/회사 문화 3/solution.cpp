#include <iostream>
#include <vector>

typedef long long ll;

std::vector<int> v[1 << 17];
bool visited[1 << 17];

int start[1 << 17];
int end[1 << 17];

int cnt = 0;

void dfs(int node)
{
    start[node] = cnt++;
    visited[node] = true;
    for (auto x : v[node])
    {
        if (visited[x])
            continue;
        dfs(x);
    }
    end[node] = cnt - 1;
}

ll tree[1 << 19];

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = 0;
        return;
    }
    int m = (l + r) >> 1;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int l, int r, int idx, ll x)
{
    if (r < idx || l > idx)
        return;
    if (l == r)
    {
        tree[node] += x;
        return;
    }
    int m = (l + r) >> 1;
    update(node * 2, l, m, idx, x);
    update(node * 2 + 1, m + 1, r, idx, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int l, int r, int s, int e)
{
    if (l > e || r < s)
    {
        return 0;
    }
    if (l >= s && r <= e)
    {
        return tree[node];
    }
    int m = (l + r) >> 1;
    return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    for (int i = 1, a; i <= N; i++)
    {
        std::cin >> a;
        if(a >= 0){
            v[a].push_back(i);
        }
    }

    // std::cout << "dfs\n";
    dfs(1);
    // std::cout << "init\n";
    init(1, 0, N - 1);

    ll a, b, c;
    while (M--)
    {
        std::cin >> a >> b;
        if (a == 1)
        {
            std::cin >> c;
            update(1, 0, N - 1, start[b], c);
        }
        else
        {
            std::cout << query(1, 0, N - 1, start[b], end[b]) << "\n";
        }
    }

    return 0;
}