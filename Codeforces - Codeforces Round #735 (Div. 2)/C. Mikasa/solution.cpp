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
#include <bitset>
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

class Node
{
public:
    ll lcnt, rcnt;
    Node *zero = nullptr, *one = nullptr;

    void insert(ll a, ll pos = 31)
    {
        // std::cout << pos << "\n";
        if (pos < 0)
            return;
        ll p = (1LL << pos);
        if (a & p)
        {
            if (one == nullptr)
            {
                one = (Node *)malloc(sizeof(Node));
                one->zero = nullptr;
                one->one = nullptr;
                one->lcnt = 0;
                one->rcnt = 0;
            }
            one->insert(a, pos - 1);
        }
        else
        {
            // std::cout << "zero\n";
            if (zero == nullptr)
            {
                zero = (Node *)malloc(sizeof(Node));
                zero->zero = nullptr;
                zero->one = nullptr;
                zero->lcnt = 0;
                zero->rcnt = 0;
            }
            zero->insert(a, pos - 1);
        }
    }

    void clean()
    {
        if (one != nullptr)
        {
            one->clean();
            free(one);
            one = nullptr;
        }
        if (zero != nullptr)
        {
            zero->clean();
            free(zero);
            zero = nullptr;
        }
    }

    ll count(ll a, ll pos = 31)
    {
        if (pos < 0)
            return 1;

        ll p = (1LL << pos);

        ll ret = 0;
        if (zero == nullptr)
        {
            lcnt = p;
            rcnt = one->count(a - p, pos - 1);
        }
        else
        {
            lcnt = zero->count(a, pos - 1);
            rcnt = a - lcnt;
        }

        return ret;
    }

    ll query(ll a, ll pos = 31)
    {
        // std::cout << pos << ":\n";
        if (pos < 0)
            return 1;

        ll p = (1LL << pos);

        if (a & p)
        {
            Node *temp = zero;
            zero = one;
            one = temp;
            ll tmp = lcnt;
            lcnt = rcnt;
            rcnt = tmp;
        }

        ll ret = 0;
        if (lcnt == p)
        {
            ret += lcnt;
            if (lcnt == p)
                ret += one->query(a, pos - 1);
        }
        else
        {
            ret += zero->query(a, pos - 1);
        }

        return ret;
    }
};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N >> M;

        Node *node = (Node *)malloc(sizeof(Node));
        node->one = nullptr;
        node->zero = nullptr;
        node->lcnt = 0;
        node->rcnt = 0;

        node->insert(M);
        node->count(M);

        std::cout << node->query(N) << "\n";

        node->clean();
        free(node);
    }

    return 0;
}
