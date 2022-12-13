#include <bits/stdc++.h>

using namespace std;

auto main(void) -> int {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        cout << s;
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }

    return 0;
}