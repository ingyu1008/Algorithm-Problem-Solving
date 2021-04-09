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

std::vector<int> nums;
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

void query1(int l, int r)
{
    flip(1, r);
    flip(1, r - l + 1);
    flip(r - l + 2, r);
}

void query2(int l, int r)
{
    flip(l, tree->cnt - 2);
    flip(tree->cnt - 2 - r + l, tree->cnt - 2);
    flip(l, tree->cnt - 2 - r + l - 1);
}

void dfs(Node *x)
{
    lazy(x);
    if (x->l)
        dfs(x->l);
    if (x->c != 0)
        nums.push_back(x->c);
    if (x->r)
        dfs(x->r);
}

void dfs2(Node *x)
{
    lazy(x);
    if (x->l)
        dfs2(x->l);
    if (x->c != 0){
        x->c = nums.back();
        nums.pop_back();
    }
    if (x->r)
        dfs2(x->r);
}

void shuffle(std::vector<int> &v)
{
    std::vector<int> tmp;
    int m = (v.size() + 1) / 2;
    for (int i = 0; i < v.size(); i++)
    {
        tmp.push_back(v[i / 2 + (i & 1) * m]);
    }
    for (int i = 0; i < v.size(); i++)
    {
        v[v.size() - i - 1] = tmp[i];
    }
}

void query3(int l, int r)
{
    nums.clear();
    getRange(l, r);
    Node *range = tree->r->l;
    dfs(range);
    shuffle(nums);
    dfs2(range);
}

void query4(Node *x)
{
    lazy(x);
    if (x->l)
        query4(x->l);
    if (x->c != 0)
        std::cout << x->c << " ";
    if (x->r)
        query4(x->r);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;
    push_back(0);
    for (int i = 1; i <= N; i++)
    {
        push_back(i);
    }
    push_back(0);

    int q, x, y;
    while (Q--)
    {
        std::cin >> q >> x >> y;
        if (q == 1)
        {
            query1(x, y);
        }
        else if (q == 2)
        {
            query2(x, y);
        }
        else
        {
            query3(x, y);
        }
    }

    query4(tree);

    return 0;
}