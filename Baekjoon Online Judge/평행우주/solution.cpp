#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Tree{
    struct Node {
        int sz;
        vector<int> E;

        Node():sz(1){};
        
        auto addEdge(int v) -> void{
            E.push_back(v);
        };
    };

    vector<Node> tree;
    vector<int> centroids;

    Tree(int sz) : tree(sz) {};

    auto addEdge(int u, int v) -> void{
        tree[u].addEdge(v);
        tree[v].addEdge(u);
    };

    auto getSize(int node, int par = -1) -> int {
        tree[node].sz = 1;
        for(auto &nxt : tree[node].E){
            if(nxt == par) continue;
            tree[node].sz += getSize(nxt, node);
        }
        return tree[node].sz;
    }

    // ref justicehui.github.io
    auto getCentroid(int node, int size, int par = -1) -> int {
        int ch = 0;
        for(auto &nxt : tree[node].E){
            if(nxt == par) continue;
            int now = getCentroid(nxt, size, node);
            if(now > (size / 2)) break;
            ch += now;
        }

        if(size - ch - 1 <= size / 2) centroids.push_back(node);

        return ch + 1;
    }

    auto eulerTour(int node, int par = -1) -> pair<ll, int> {
        pair<ll, int> ret = {1, 1};
        vector<pair<ll, int>> res;
        for(auto &nxt : tree[node].E){
            if(nxt == par) continue;
            res.push_back(eulerTour(nxt, node));
        }
        sort(res.begin(), res.end());
        for(auto &x : res){
            ret.first <<= x.second;
            ret.first |= x.first;
            ret.second += x.second;
        }
        ret.first <<= 1;
        ret.second++;
        return ret;
    }
};

auto main(void) -> int {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ll> trees;

    for(int i = 0; i < N; i++){
        int S;
        cin >> S;
        Tree T(S);
        for(int i = 0, u, v; i < S-1; i++){
            cin >> u >> v;
            T.addEdge(u, v);
        }
        T.getSize(0);
        T.getCentroid(0, S);

        ll hash = 0;

        for(auto &c : T.centroids){
            hash = max(hash, T.eulerTour(c).first);
        }

        trees.push_back(hash);
    }

    sort(trees.begin(), trees.end());
    trees.erase(unique(trees.begin(), trees.end()), trees.end());

    cout << trees.size() << "\n";

    return 0;
}