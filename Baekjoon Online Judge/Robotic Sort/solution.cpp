#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
    int c;
    int cnt;
    Node *l, *r, *p;
    bool flip = false;
} * tree;

std::vector<Node *> ptrs;
void lazy(Node *x)
{
    if (!x || !x->flip)
        return;
    Node *tmp = x->l;
    x->l = x->r;
    x->r = tmp;
    x->flip = false;
    if (x->l)
        x->l->flip = !x->l->flip;
    if (x->r)
        x->r->flip = !x->r->flip;
}

void update(Node *x)
{
    x->cnt = 1;
    if (x->l)
        x->cnt += x->l->cnt;
    if (x->r)
        x->cnt += x->r->cnt;
}

void rotate(Node *x)
{
    Node *p = x->p;
    Node *b;

    lazy(p);
    lazy(x);

    if (x == p->l)
    {
        b = x->r;
        x->r = p;
        x->p = p->p;
        p->p = x;
        p->l = b;
    }
    else
    {
        b = x->l;
        x->l = p;
        x->p = p->p;
        p->p = x;
        p->r = b;
    }

    if (b)
        b->p = p;

    if (x->p)
    {
        if (p == x->p->l)
        {
            x->p->l = x;
        }
        else
        {
            x->p->r = x;
        }
    }
    else
    {
        tree = x;
    }

    update(p);
    update(x);
}

void splay(Node *x)
{
    while (x->p)
    {
        if (x->p->p)
        {
            if ((x == x->p->l) == (x->p == x->p->p->l))
            {
                rotate(x->p);
            }
            else
            {
                rotate(x);
            }
        }
        rotate(x);
    }
}

Node *push_back(int c)
{
    Node *last = tree;

    if (last)
    {
        lazy(last);
        while (last->r)
        {
            last = last->r;
            lazy(last);
        }
        Node *x = new Node;
        x->l = NULL;
        x->r = NULL;
        x->p = last;
        x->c = c;
        last->r = x;
        splay(x);
        return x;
    }
    else
    {
        Node *x = new Node;
        x->l = NULL;
        x->r = NULL;
        x->p = NULL;
        x->c = c;
        tree = x;
        return x;
    }
}

void find_kth(int k)
{
    Node *x = tree;
    while (1)
    {
        lazy(x);
        while (x->l && x->l->cnt > k)
        {
            x = x->l;
            lazy(x);
        }
        if (x->l)
            k -= x->l->cnt;
        if (k == 0)
            break;
        k--;
        x = x->r;
    }
    splay(x);
}

void getRange(int l, int r)
{
    find_kth(l - 1);
    Node *x = tree;
    tree = x->r;
    tree->p = NULL;
    find_kth(r - l + 1);
    x->r = tree;
    tree->p = x;
    tree = x;
}

void flip(int l, int r)
{
    if (l >= r)
        return;
    getRange(l, r);
    tree->r->l->flip = !tree->r->l->flip;
}

void free()
{
    for (int i = 0; i < ptrs.size(); i++)
    {
        delete ptrs[i];
    }
    ptrs.clear();
    tree = NULL;
}

void query(int i)
{
    splay(ptrs[i]);
    std::cout << tree->l->cnt << " ";
    flip(i, tree->l->cnt);
}
int main(void)
{
    // std::cin.tie(0);
    // std::ios_base::sync_with_stdio(false);

    int N, x;
    while (std::cin >> N)
    {
        if (N == 0)
            break;
        auto &ptr = ptrs;
        ptrs.resize(N + 2);
        ptrs[0] = push_back(0);

        std::vector<std::pair<int, int>> v(N);

        for (int i = 0; i < N; i++)
        {
            std::cin >> x;
            v[i] = {x, i};
        }
        std::sort(v.begin(), v.end());

        std::vector<int> vv(N);

        for (int i = 0; i < N; i++)
        {
            vv[v[i].second] = i + 1;
        }

        for (int i = 0; i < N; i++)
        {
            ptrs[vv[i]] = push_back(vv[i]);
        }

        ptrs[N + 1] = push_back(N + 1);

        for (int i = 1; i <= N; i++)
        {
            query(i);
        }
        std::cout << "\n";
        free();
    }

    return 0;
}