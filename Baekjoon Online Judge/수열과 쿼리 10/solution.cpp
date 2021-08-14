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

struct Node
{
    ll lsum, rsum, sum, mx;
} tree[1 << 19];

Node merge(Node l, Node r)
{
    if (l.lsum == -1e18)
        return r;
    if (r.lsum == -1e18)
        return l;
    Node node;
    node.lsum = std::max(l.lsum, l.sum + r.lsum);
    node.rsum = std::max(r.rsum, l.rsum + r.sum);
    node.sum = l.sum + r.sum;
    node.mx = std::max(l.rsum + r.lsum, std::max(l.mx, std::max(r.mx, node.sum)));
    return node;
}

ll a[1 << 18];

void init(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int m = (l + r) >> 1;
    init(node * 2, l, m);
    init(node * 2 + 1, m + 1, r);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int l, int r, int s, int e)
{
    if (l > e || r < s)
        return {(ll)-1e18, (ll)-1e18, (ll)-1e18, (ll)-1e18};
    if (l >= s && r <= e)
    {
        return tree[node];
    }
    int m = (l + r) >> 1;
    return merge(query(node * 2, l, m, s, e), query(node * 2 + 1, m + 1, r, s, e));
}

int N;
ll solve(int x, int y, int z, int w)
{
    Node L = query(1, 0, N - 1, x, y - 1);
    Node M = query(1, 0, N - 1, y, z);
    Node R = query(1, 0, N - 1, z + 1, w);
    // std::cout << L.rsum << " " << M.sum << " " << R.lsum << "\n";
    return std::max(L.rsum, 0LL) + M.sum + std::max(R.lsum, 0LL);
}

ll solve2(int x, int y, int z, int w)
{
    Node M = query(1, 0, N - 1, z, y);
    // std::cout << L.rsum << " " << M.sum << " " << R.lsum << "\n";
    return M.mx;
}


int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }

    init(1, 0, N - 1);

    int M, x, y, z, w;
    std::cin >> M;
    while (M--)
    {
        std::cin >> x >> y >> z >> w;
        x--, y--, z--, w--;

        if (x <= w)
        {
            if (y <= z)
            {
                std::cout << solve(x,y,z,w) << "\n";
            }
            else
            {
                ll ans1 = solve(x,y,y,w);
                ll ans2 = solve(x,z,z,w);
                ll ans3 = solve(x,z,y,w);
                ll ans4 = solve2(x,y,z,w);

                std::cout << std::max(std::max(ans1, ans2), std::max(ans3,ans4)) << "\n";
            }
        }
        else
        {
            std::cout << "0\n";
        }
    }

    return 0;
}
