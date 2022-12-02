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
            for(int i = 0; i < N; i++) cout << "1 ";
            cout << "\n";
        } else {
            for(int i = 0; i < N-2; i++) cout << "2 ";
            cout << "1 3\n";
        }
    }

    return 0;
}