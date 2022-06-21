#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string X;
    std::cin >> X;

    std::vector<ll> A(505050);

    for (int i = 0; i < X.size(); i++) {
        A[i] += X[i] - '0';
        A[i + 1] = A[i];
    }

    std::stack<ll> st;

    for(int i = X.size() - 1; i >= 0; i--){
        st.push(A[i]%10);
        if(i > 0) A[i-1] += A[i]/10;
        else if(A[i] >= 10) st.push(A[i]/10);
    }

    while(!st.empty()){
        std::cout << st.top();
        st.pop();
    }

    return 0;
}