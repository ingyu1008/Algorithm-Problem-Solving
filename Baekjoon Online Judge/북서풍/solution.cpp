#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

std::vector<int> x, y;
std::vector<std::pair<int, int>> v;

ll tree[404040];

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
    tree[node] = 0;
}

void update(int node, int l, int r, int idx)
{
    if (l > idx || r < idx)
        return;
    if (l == r)
    {
        tree[node]++;
        return;
    }
    int m = (l + r) >> 1;
    update(node * 2, l, m, idx);
    update(node * 2 + 1, m + 1, r, idx);
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
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N;
        std::cin >> N;
        v.clear(), x.clear(), y.clear();
        v.resize(N), x.resize(N), y.resize(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i].first >> v[i].second;
            v[i].first = -v[i].first;
            x[i] = v[i].first;
            y[i] = v[i].second;
        }

        std::sort(x.begin(), x.end());
        x.erase(std::unique(x.begin(), x.end()), x.end());

        std::sort(y.begin(), y.end());
        y.erase(std::unique(y.begin(), y.end()), y.end());

        for (int i = 0; i < N; i++)
        {
            v[i].first = std::lower_bound(x.begin(), x.end(), v[i].first) - x.begin();
            v[i].second = std::lower_bound(y.begin(), y.end(), v[i].second) - y.begin();
        }

        std::sort(v.begin(),v.end());

        int mx = y.size() - 1;
        init(1, 0, mx);

        ll ans = 0;

        for (int i = 0; i < N; i++)
        {
            ans += query(1, 0, mx, 0, v[i].second);
            update(1, 0, mx, v[i].second);
        }

        std::cout << ans << "\n";
    }

    return 0;
}
