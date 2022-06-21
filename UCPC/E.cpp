#include <iostream>
#include <vector>

typedef long long ll;

int main(void)
{
    int N, K;
    std::cin >> N >> K;

    std::vector<ll> A(N), B(N);

    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N; i++){
        std::cin >> B[i];
    }

    

    return 0;
}