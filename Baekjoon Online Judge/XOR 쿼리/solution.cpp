/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
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
    int cnt, s, e, l, r;
};

std::vector<Node> tree;
int roots[505050];

int addNode(int s, int e) {
    int idx = tree.size();
    tree.push_back({ 0, s, e, -1, -1 });
    return idx;
}

void init(int node, int s, int e) {
    if (s == e) {
        return;
    }

    int mid = (s + e) / 2;
    int l = addNode(s, mid);
    int r = addNode(mid + 1, e);
    tree[node].l = l;
    tree[node].r = r;

    init(l, s, mid);
    init(r, mid + 1, e);
}

int createTree(int len, int s, int e) {
    int idx = addNode(s, e);
    roots[len + 1] = idx;
    tree[idx].cnt = tree[roots[len]].cnt;
    tree[idx].l = tree[roots[len]].l;
    tree[idx].r = tree[roots[len]].r;

    return idx;
}

// caller must ensure that node is added before calling this function
// caller must ensure that node's l and r is pointing to previous tree's l and r
void insert(int val, int node) {
    if (tree[node].s == tree[node].e) {
        tree[node].cnt++;
        return;
    }

    if (val <= tree[tree[node].l].e) {
        int tmp = addNode(tree[node].s, tree[tree[node].l].e);
        tree[tmp].cnt = tree[tree[node].l].cnt;
        tree[tmp].l = tree[tree[node].l].l;
        tree[tmp].r = tree[tree[node].l].r;
        tree[node].l = tmp;
        insert(val, tmp);
        tree[node].cnt++;
    } else {
        int tmp = addNode(tree[tree[node].r].s, tree[node].e);
        tree[tmp].cnt = tree[tree[node].r].cnt;
        tree[tmp].l = tree[tree[node].r].l;
        tree[tmp].r = tree[tree[node].r].r;
        tree[node].r = tmp;
        insert(val, tmp);
        tree[node].cnt++;
    }
}

int countLessThan(int node, int x) {
    if (tree[node].s > x)
        return 0;
    if (tree[node].e <= x) {
        return tree[node].cnt;
    }

    return countLessThan(tree[node].l, x) + countLessThan(tree[node].r, x);
}

void query1(int& N, int x) {
    insert(x, createTree(N++, 0, (1 << 19) - 1));
}

void query2(int L, int R, int x) {
    int msb = 1 << 18;
    int ans = 0;

    int prev = R - L + 1;

    while (msb) {
        // int i = countLessThan(roots[R], ans + 2 * msb - 1) - countLessThan(roots[L - 1], ans + 2 * msb - 1);
        int j = countLessThan(roots[R], ans + msb - 1) - countLessThan(roots[L - 1], ans + msb - 1);
        int k = countLessThan(roots[R], ans - 1) - countLessThan(roots[L - 1], ans - 1);

        int tmp = (x & msb);
        // if (i > j) {
        if (k == j || (j - k < prev && !tmp)) {
            ans += msb;
            prev -= j - k;
        } else {
            prev = j - k;
        }
        // }
        msb >>= 1;
    }

    std::cout << ans << "\n";
}

void query3(int& N, int k) {
    N -= k;
}

void query4(int L, int R, int x) {
    int ans = countLessThan(roots[R], x) - countLessThan(roots[L - 1], x);

    std::cout << ans << "\n";
}

int _query5(int nodeL, int nodeR, int k) {
    if (tree[nodeL].s == tree[nodeL].e) {
        return tree[nodeL].e;
    }

    int mid = (tree[nodeL].s + tree[nodeL].e) / 2;
    int left = tree[tree[nodeR].l].cnt - tree[tree[nodeL].l].cnt;
    if (left >= k) {
        return _query5(tree[nodeL].l, tree[nodeR].l, k);
    } else {
        return _query5(tree[nodeL].r, tree[nodeR].r, k - left);
    }

}

void query5(int L, int R, int k) {
    std::cout << _query5(roots[L-1], roots[R], k) << "\n";
}


int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N = 0;
    int M;
    std::cin >> M;

    roots[0] = addNode(0, (1 << 19) - 1);
    init(0, 0, (1 << 19) - 1);

    for (int i = 0; i < M; i++) {
        int q;
        std::cin >> q;
        if (q == 1) {
            int x;
            std::cin >> x;
            query1(N, x);
        } else if (q == 2) {
            int L, R, x;
            std::cin >> L >> R >> x;
            query2(L, R, x);
        } else if (q == 3) {
            int k;
            std::cin >> k;
            query3(N, k);
        } else if (q == 4) {
            int L, R, x;
            std::cin >> L >> R >> x;
            query4(L, R, x);
        } else if (q == 5) {
            int L, R, k;
            std::cin >> L >> R >> k;
            query5(L, R, k);
        }
    }


    return 0;
}
