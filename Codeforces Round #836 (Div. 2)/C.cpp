#include <bits/stdc++.h>

using namespace std;

auto main(void) -> int {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        int N, x;
        cin >> N >> x;

        if((N % x)){
            cout << "-1\n";
            continue;
        }

        vector<int> v(N+1);
        iota(v.begin(), v.end(), 0);

        v[1] = x;
        v[N] = 1;

        while(x < N) for(int i = x*2; i <= N; i+= x){
            if((N%i) == 0) {
                v[x] = i;
                x = i;
                break;
            }
        }

        for(int i = 1; i <= N; i++){
            cout << v[i] << " ";
        }
        cout << "\n";        
    }

    return 0;
}