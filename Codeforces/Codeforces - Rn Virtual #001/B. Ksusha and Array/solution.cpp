#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    
    int x,y = 0;
    std::set<int> st;

    for(int i = 0; i < N; i++){
        std::cin >> x;
        y = gcd(x, y);
        st.insert(x);
    }

    if(st.find(y) == st.end()){
        std::cout << "-1\n";
    } else {
        std::cout << y << "\n";
    }

    return 0;
}