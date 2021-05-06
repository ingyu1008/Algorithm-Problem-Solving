//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> tree(1010101, -1);

void update(int node)
{
    while (node)
    {
        tree[node]++;
        node >>= 1;
    }
}

bool query(int node, int l, int r, int k)
{
    if (l != r)
    {
        int m = (l + r) >> 1;
        if (tree[node * 2] == -1)
        {
            std::cout << "? " << l << " " << m << std::endl;
            std::cin >> tree[node * 2];
        }
        if (m - l + 1 - tree[node * 2] < k)
        {
            return query(node * 2 + 1, m + 1, r, k - (m - l + 1 - tree[node * 2]));
        }
        else
        {
            return query(node * 2, l, m, k);
        }
    }
    else
    {
        std::cout << "! " << l << std::endl;
        update(node);
        return true;
    }
}

int main(void)
{
    int N, T;
    std::cin >> N >> T;

    for (int i = 0, k; i < T; i++)
    {
        std::cin >> k;
        query(1, 1, N, k);
    }

    return 0;
}
