/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<pii> vpii;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
        b = (b * a) % mod;
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        a ^= b ^= a ^= b;
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

/********************************************************************
						End Of Template
********************************************************************/

struct Node {
    int l, r, p;
    int cnt, sum, val, flip;
    Node(): l(0), r(0), p(0), cnt(1), sum(0), flip(0) {}
};

struct LCT {
    std::vector<Node> tree;

    void init(int n, std::vector<int> &v){
        tree.resize(n+1);
        for(int i = 1; i <= n; i++) tree[i].val = v[i], tree[i].sum = v[i];
    }

    bool exists(int x){
        return x > 0;
    }

    bool isRoot(int x){
        return (!exists(tree[x].p) || (tree[tree[x].p].l != x && tree[tree[x].p].r != x));
    }
    
    int newNode(){
        tree.push_back(Node());
        return tree.size() - 1;
    }

    void lazy(int x){
        if(tree[x].flip == 0) return;
        else {
            tree[x].flip = 0;
            int l = tree[x].l;
            int r = tree[x].r;
            std::swap(tree[x].l, tree[x].r);

            if(exists(l)) tree[l].flip ^= 1;
            if(exists(r)) tree[r].flip ^= 1;
        }
    }

    void update(int x){
        tree[x].cnt = 1;
        tree[x].sum = tree[x].val;
        if(exists(tree[x].l)){
            tree[x].cnt += tree[tree[x].l].cnt;
            tree[x].sum += tree[tree[x].l].sum;
        }
        if(exists(tree[x].r)){
            tree[x].cnt += tree[tree[x].r].cnt;
            tree[x].sum += tree[tree[x].r].sum;
        }
    }

    void rotate(int x){
        int p = tree[x].p;
        if(x == tree[p].l){
            tree[p].l = tree[x].r;
            tree[x].r = p;
            if(exists(tree[p].l)) tree[tree[p].l].p = p;
        } else {
            tree[p].r = tree[x].l;
            tree[x].l = p;
            if(exists(tree[p].r)) tree[tree[p].r].p = p;
        }

        tree[x].p = tree[p].p;
        tree[p].p = x;

        if(exists(tree[x].p)){
            if(p == tree[tree[x].p].l) tree[tree[x].p].l = x;
            else if(p == tree[tree[x].p].r) tree[tree[x].p].r = x;
        }

        update(p);
        update(x);
    }

    void splay(int x){
        while(!isRoot(x)){
            int p = tree[x].p;
            if(!isRoot(p)) lazy(tree[p].p);
            lazy(p);
            lazy(x);
            if(!isRoot(p)){
                if((x == tree[p].l) == (p == tree[tree[p].p].l)) rotate(p);
                else rotate(x);
            }
            rotate(x);
        }
        lazy(x);
    }
    
    int access(int x){
        splay(x);
        tree[x].r = 0;
        update(x);

        int ret = x;
        while(exists(tree[x].p)){
            int p = tree[x].p;
            ret = p;
            splay(p);
            tree[p].r = x;
            update(p);
            splay(x);
        }

        return ret;
    }

    void link(int x, int y){
        access(x);
        access(y);

        tree[x].l = y;
        tree[y].p = x;
        update(x);
    }

    void cut(int x){
        access(x);
        tree[tree[x].l].p = 0;
        tree[x].l = 0;
        update(x);
    }

    int lca(int x, int y){
        access(x);
        return access(y);
    }

    int findRoot(int x){
        access(x);
        while(exists(tree[x].l)) x = tree[x].l;
        splay(x);
        return x;
    }

    int parent(int x){
        access(x);
        x = tree[x].l;
        if(!exists(x)) return 0;
        
        while(tree[x].r) x = tree[x].r;
        splay(x);
        return x;
    }

    int depth(int x){
        access(x);
        if(exists(tree[x].l)) return tree[tree[x].l].cnt;
        return 0;
    }

    int sumPath(int x, int y){
        int p = lca(x, y);
        int sum = tree[p].val;

        access(x);
        splay(p);
        if(exists(tree[p].r)) sum += tree[tree[p].r].sum;

        access(y);
        splay(p);
        if(exists(tree[p].r)) sum += tree[tree[p].r].sum;

        return sum;
    }

    void update(int x, int y){
        access(x);
        tree[x].val = y;
        update(x);
    }

    bool connected(int x, int y){
        return findRoot(x) == findRoot(y);
    }

    void makeRoot(int x){
        access(x);
        splay(x);
        tree[x].flip ^= 1;
    }
};

struct Solver{
    LCT *lct;

    int N, Q;
    std::vector<int> v;

    void init(){
        std::cin >> N;

        v.resize(N+1);
        for(int i = 1; i <= N; i++) std::cin >> v[i];

        lct = new LCT();
        lct->init(N, v);

        std::cin >> Q;
    }

    void solve(){
        std::string op;
        int A, B;
        for(int i = 0; i < Q; i++){
            std::cin >> op >> A >> B;
            if(op == "bridge"){
                if(lct->connected(A, B)){
                    std::cout << "no" << std::endl;
                    continue;
                } else {
                    std::cout << "yes" << std::endl;
                    lct->makeRoot(A); lct->makeRoot(B);
                    lct->link(A, B);
                }
            } else if(op == "penguins"){
                lct->update(A, B);
            } else if(op == "excursion"){
                if(lct->connected(A, B)){
                    std::cout << lct->sumPath(A, B) << std::endl;
                } else {
                    std::cout << "impossible" << std::endl;
                }
            }
        }
    }
};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    Solver solver;
    solver.init();

    solver.solve();    

    return 0;
}
