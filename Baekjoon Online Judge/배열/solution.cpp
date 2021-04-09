#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct Node
{
    ll c, cnt, mn, mx, sum;
    Node *l, *r, *p;
    bool flip = false;
} * tree;

std::vector<Node *> ptrs;

void lazy(Node *x)
{
    if (!x->flip)
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
    x->mn = x->c;
    x->mx = x->c;
    x->sum = x->c;
    if (x->l)
    {
        x->cnt += x->l->cnt;
        x->mn = std::min(x->mn, x->l->mn);
        x->mx = std::max(x->mx, x->l->mx);
        x->sum += x->l->sum;
    }
    if (x->r)
    {
        x->cnt += x->r->cnt;
        x->mn = std::min(x->mn, x->r->mn);
        x->mx = std::max(x->mx, x->r->mx);
        x->sum += x->r->sum;
    }
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

void push_back(ll c)
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

Node *find_kth(ll k)
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

Node *getRange(ll l, ll r)
{
    find_kth(l - 1);
    Node *x = tree;
    tree = x->r;
    tree->p = NULL;
    find_kth(r - l + 1);
    x->r = tree;
    tree->p = x;
    tree = x;
    return tree->r->l;
}

void flip(ll l, ll r)
{
    if (l >= r)
        return;
    getRange(l, r);
    tree->r->l->flip = !tree->r->l->flip;
}

void shift(ll l, ll r, ll x)
{
    flip(l, r);
    flip(l, l + x - 1);
    flip(l + x, r);
}

void query1(ll l, ll r)
{
    Node *range = getRange(l, r);
    std::cout << range->mn << " " << range->mx << " " << range->sum << "\n";
    flip(l, r);
}

void query2(ll l, ll r, ll x)
{
    Node *range = getRange(l, r);
    std::cout << range->mn << " " << range->mx << " " << range->sum << "\n";
    shift(l, r, (x % (r - l + 1) + r - l + 1) % (r - l + 1));
}

void query3(ll i)
{
    Node *node = find_kth(i);
    std::cout << node->c << "\n";
}

void query4(ll i)
{
    splay(ptrs[i]);
    std::cout << tree->l->cnt << "\n";
}

void query5(ll i)
{
    Node *node = find_kth(i);
    std::cout << node->c << " ";
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N, Q;
    std::cin >> N >> Q;
    push_back(0);
    ptrs.push_back(tree);
    for (int i = 1; i <= N; i++)
    {
        push_back(i);
        ptrs.push_back(tree);
    }
    push_back(N + 1);
    ptrs.push_back(tree);

    ll q, l, r, x;

    while (Q--)
    {
        std::cin >> q;
        if (q == 1)
        {
            std::cin >> l >> r;
            query1(l, r);
        }
        else if (q == 2)
        {
            std::cin >> l >> r >> x;
            query2(l, r, x);
        }
        else if (q == 3)
        {
            std::cin >> x;
            query3(x);
        }
        else if (q == 4)
        {
            std::cin >> x;
            query4(x);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        query5(i);
    }

    return 0;
}