#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    ll a = 0, b = 0;
    std::vector<ll> v(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
        b += v[i];
    }

    std::sort(v.begin(), v.end());

    for(int i = 0; i < N/2; i++){
        a += v[i];
        b -= v[i];
    }

    std::cout << a*a + b*b << "\n";

    return 0;
}