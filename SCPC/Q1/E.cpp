#include <iostream>

struct Node
{
    int par;
    int root;
    bool cf = false;
    bool lazycf = false;
    int value = 0;
    int dep = 0;
} tree[1 << 18];

void lazy(int node)
{
    if (!tree[node].cf)
        return;
    tree[node].cf = true;

    for (int i = 0; i < 18; i++)
    {
        if (tree[node].cf)
            continue;
        tree[node].lazycf = true;
    }
}

void query1(int a, int b, int d)
{
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    return 0;
}