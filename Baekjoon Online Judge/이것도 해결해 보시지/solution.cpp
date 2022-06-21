#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <random>

typedef long long ll;

ll N, L;
ll mat[1024000];
ll NbyOne[4][256];
std::mt19937 gen(20220107);

void make_rand() {
    for (int i = 0; i < N; i++) {
        NbyOne[0][i] = gen() % 150000;
    }
}

bool possible(int c) {
    for (int t = 0; t < 60; t++) {
        make_rand();
        for (int i = 0; i < N; i++) {
            NbyOne[1][i] = 0;
            NbyOne[2][i] = 0;
            for (int j = 0; j < N; j++) {
                NbyOne[1][i] += mat[i * L + c + N + j] * NbyOne[0][j];
                NbyOne[2][i] += mat[i * L + c + 2 * N + j] * NbyOne[0][j];
            }
        }
        for (int i = 0; i < N; i++) {
            NbyOne[3][i] = 0;
            for (int j = 0; j < N; j++) {
                NbyOne[3][i] += mat[i * L + c + j] * NbyOne[1][j];
            }
            if (NbyOne[3][i] != NbyOne[2][i]) {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            std::cin >> mat[i * L + j];
        }
    }

    ll ans = 0;
    for (int i = 0; i + 3 * N <= L; i++) {
        if (possible(i)) {
            ans += N * N * 3;
            i += 3 * N - 1;
        }
    }

    std::cout << ans << "\n";


    return 0;
}
