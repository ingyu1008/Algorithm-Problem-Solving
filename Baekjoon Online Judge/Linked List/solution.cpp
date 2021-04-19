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

void push_back(int c)
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
    }
    else
    {
        Node *x = new Node;
        x->l = NULL;
        x->r = NULL;
        x->p = NULL;
        x->c = c;
        tree = x;
    }
}

Node *find_kth(int k)
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
    return tree;
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

void remove(Node *x)
{
    splay(x);
    tree = x->l;
    Node *l = x->l;
    while (l->r)
    {
        l = l->r;
    }
    l->r = x->r;
    if (x->r)
        x->r->p = l;
    tree->p = NULL;
    update(tree);
}

Node *insert(Node *x, int c)
{
    splay(x);
    Node *y = new Node;
    y->l = NULL;
    y->r = x->r;
    y->p = x;
    y->c = c;

    if (x->r)
        x->r->p = y;
    x->r = y;
    splay(y);
    return y;
}

void query(int a, int b)
{
    splay(ptrs[a]);

    Node *tr = tree;
    int original = tree->l->cnt;
    splay(ptrs[b]);
    int now = tree->l->cnt + 1;
    if (original < now)
        now--;
    std::cout << now - original << "\n";
    remove(ptrs[a]);
    Node *tmp = insert(ptrs[b], ptrs[a]->c);
    delete ptrs[a];
    ptrs[a] = tmp;
}

void query2(Node *x)
{
    lazy(x);
    if (x->l)
        query2(x->l);
    if (x->c > 0)
        std::cout << x->c << " ";
    if (x->r)
        query2(x->r);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;
    push_back(0);
    ptrs.push_back(tree);
    for (int i = 1; i <= N; i++)
    {
        push_back(i);
        ptrs.push_back(tree);
    }
    push_back(0);
    ptrs.push_back(tree);

    int a, b;
    while (Q--)
    {
        std::cin >> a >> b;
        query(a, b);
    }

    query2(tree);

    return 0;
}