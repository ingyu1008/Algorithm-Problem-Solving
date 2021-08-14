#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v(1010101);

struct Node
{
    long long sum;
    bool lazy;
} tree[4040404];

void lazy_push(int node, int l, int r)
{
    if (tree[node].lazy)
    {
        if (l != r)
        {
            tree[node * 2].lazy = !tree[node].lazy;
            tree[node * 2 + 1].lazy = !tree[node].lazy;
        }
        tree[node].sum = r - l + 1 - tree[node].sum;
        tree[node].lazy = 0;
    }
}

Node merge(Node a, Node b)
{
    Node node;
    node.sum = a.sum + b.sum;
    node.lazy = false;
    return node;
}

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node].sum = v[l];
        tree[node].lazy = false;
    }
    else
    {
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
    }
}

void update(int node, int l, int r, int s, int e)
{
    lazy_push(node, l, r);
    if (l > e || r < s)
    {
        return;
    }
    if (l >= s && r <= e)
    {
        tree[node].lazy = !tree[node].lazy;
        lazy_push(node, l, r);
        return;
    }

    int m = (l + r) / 2;
    update(node * 2, l, m, s, e);
    update(node * 2 + 1, m + 1, r, s, e);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

long long query(int node, int l, int r, int s, int e)
{
    lazy_push(node, l, r);
    if (l > e || r < s)
    {
        return 0;
    }
    if (l >= s && r <= e)
    {
        return tree[node].sum;
    }
    int m = (l + r) / 2;
    return query(node * 2, l, m, s, e) + query(node * 2 + 1, m + 1, r, s, e);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    init(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        std::cout << query(1, 1, n, 1, n) << " ";
    }

    update(1, 1, n, 2, 3);

    for (int i = 1; i <= n; i++)
    {
        std::cout << query(1, 1, n, 1, n) << " ";
    }

    // for (int i = 1; i <= m; i++) {
    // 	int a,b,c;
    // 	cin >> a>>b>>c;
    // 	if (a == 0) {
    // 		update(1, 1, n, b, c);
    // 	}
    // 	else {
    // 		cout << query(1, 1, n, b, c) << "\n";
    // 	}
    // }
    return 0;
}