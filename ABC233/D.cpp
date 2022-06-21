#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> A(N);
    std::vector<ll> B(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(i == 0) B[i] = A[i];
        else B[i] = B[i - 1] + A[i];
    }

    ll ans = 0;
    std::map<ll, ll> dp;
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        dp[B[i]]++;
        ans += dp[B[i] - K];
    }

    std::cout << ans - (K==0)*N << "\n";

    return 0;
}