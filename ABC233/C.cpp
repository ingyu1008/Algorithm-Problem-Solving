#include <iostream>
#include <vector>
#include <map>
#include <stack>

typedef long long ll;

std::map<ll, ll> memo; // How many ways to make key

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N, X;
    std::cin >> N >> X;

    memo[1] = 1;

    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        std::map<ll, ll> newmemo;
        for (int j = 0; j < L; j++) {
            ll x;
            std::cin >> x;
            for (auto p : memo) {
                if ((p.first * x) > 0 && (X % (p.first * x)) == 0)
                    newmemo[p.first * x] += p.second;
            }
        }
        memo = newmemo;
    }

    std::cout << memo[X] << "\n";

    return 0;
}