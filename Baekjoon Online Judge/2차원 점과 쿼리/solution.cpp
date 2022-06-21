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
#include <stack>

std::map<pii, int> D, V; // count number of (x,y)
std::stack<std::pair<pii, pii>> stD, stV; // log of point insertion (x,y) and previous (maxX, maxY)
int maxDx = -1, maxDy = -1, maxVx = -1, maxVy = -1;

struct Node {
    std::vector<std::pair<int, int>> points;
} tree[1 << 20];

void addPoint(int node, int l, int r, int s, int e, pii x){
    if(l > e || r < s) return;
    if(l >= s && r <= e){
        tree[node].points.push_back(x);
        return;
    }
    int m = (l + r) / 2;
    addPoint(node * 2, l, m, s, e, x);
    addPoint(node * 2 + 1, m + 1, r, s, e, x);
}

void rollbackD(int x){
    for(int i = 0; i < x; i++){
        if(stD.empty()) break;
        auto p = stD.top().first;
        auto q = stD.top().second;
        stD.pop();

        D[p]--;
        maxDx = q.first;
        maxDy = q.second;
    }
}

void rollbackV(int x){
    for(int i = 0; i < x; i++){
        if(stV.empty()) break;
        auto p = stV.top().first;
        auto q = stV.top().second;
        stV.pop();

        V[p]--;
        maxVx = q.first;
        maxVy = q.second;
    }
}

void _query(int x){
    std::cout << 
}

void query(int node, int l, int r){

}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int Q;
    std::cin >> Q;
    while(Q--){
        int r, s, x, y;
        std::cin >> r >> s >> x >> y;
        if(r == 1){
            // insert point

        }
    }

    return 0;
}
