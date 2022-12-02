#include <bits/stdc++.h>

using namespace std;

auto main(void) -> int {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;

        if(N&1){
            int k = (N-1)/2;
            cout << N-k+1 << " ";
            for(int i = -k+3; i <= k; i++){
                cout << N + i << " ";
            }
            cout << N+k+2 << " " << N+k+3 << "\n";
        } else {
            for(int i = -(N/2); i <= N/2; i++){
                if(i == 0) continue;
                cout << N + i << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}