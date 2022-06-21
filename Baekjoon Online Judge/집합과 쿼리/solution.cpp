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
#include <bitset>
#include <stack>

struct Node {
    std::vector<int> v;
} tree[2020202];

std::vector<std::bitset<32>> basis(32);
std::stack<std::pair<int, std::bitset<32>>> st;

int makeRREF(int idx){
    int rb = 0;
    for (int i = 0; i < 32; i++) {
        if (basis[i].none()) {
            continue;
        }
        for (int j = i + 1; j < 32; j++) {
            if (basis[j].test(i)) {
                st.push({j, basis[j]});
                rb++;
                basis[j] ^= basis[i];
            }
        }
    }

    return rb;
}

int insert(int x) {
    std::bitset<32> y(x);
    for (int j = 31; j >= 0; j--) {
        if (y.test(j)) {
            if (basis[j].none()) {
                st.push({j, basis[j]});
                basis[j] = y;
                return 1 + makeRREF(j);
            } else {
                y ^= basis[j];
            }
        }
    }
    return 0;
}

void rollback(int x) {
    while(x--){
        int idx = st.top().first;
        basis[idx] = st.top().second;
        st.pop();
    }
}

void add(int node, int l, int r, int s, int e, int x) {
    if (l > e || r < s) return;
    if (l >= s && r <= e) {
        tree[node].v.push_back(x);
        return;
    }
    int mid = (l + r) / 2;
    add(node * 2, l, mid, s, e, x);
    add(node * 2 + 1, mid + 1, r, s, e, x);
}

void _query() {
    int ans = 0;

    for(int i = 0; i < 32; i++){
        ans ^= basis[i].to_ulong();
    }
    
    std::cout << ans << "\n";
}

void query(int node, int l, int r) {
    int rb = 0;
    for (int i = 0; i < tree[node].v.size(); i++) {
        rb += insert(tree[node].v[i]);
    }

    if (l == r) {
        _query();
    } else {
        int mid = (l + r) / 2;
        query(node * 2, l, mid);
        query(node * 2 + 1, mid + 1, r);
    }

    rollback(rb);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::map<int, int> wait;

    for (int i = 1; i <= N; i++)
    {
        int x;
        std::cin >> x;
        if (x > 0) {
            wait[x] = i;
        } else {
            add(1, 1, N, wait[-x], i-1, -x);
            wait[-x] = 0;
        }
    }

    for(auto p : wait){
        if(p.second > 0){
            add(1, 1, N, p.second, N, p.first);
        }
    }

    query(1, 1, N);

    return 0;
}
