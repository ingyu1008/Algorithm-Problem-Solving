#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

auto main(void) -> int {
    cin.tie(0)->sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<p> pq;
    priority_queue<ll> in;

    for(ll i = 0, l, d; i < N; i++){
        cin >> l >> d;
        pq.emplace(-l-d, d);
    }

    ll h = 0;

    while(!pq.empty()){
        auto [l, d] = pq.top();
        pq.pop();
        l = -l - d;

        if(h <= l){
            h += d;
            in.push(d);
        } else if(in.top() > d && h - in.top() <= l){
            h -= in.top();
            h += d;
            in.pop();
            in.push(d);
        }
    }

    cout << in.size() << "\n";

    return 0;
}