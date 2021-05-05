//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
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

    std::vector<ll> a(N), b(N);

    ll original = 0;

    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        std::cin >> b[i];
        original += a[i] * b[i];
    }

    ll mx = original;

    //odd reverse
    for (int i = 0; i < N; i++)
    {
        ll now = original;
        int l = i;
        int r = i;
        while (l >= 0 && r < N)
        {
            now -= a[l] * b[l];
            now -= a[r] * b[r];
            now += a[l] * b[r];
            now += a[r] * b[l];
            mx = std::max(mx, now);
            l--;
            r++;
        }
    }

    //even reverse
    for (int i = 0; i < N; i++)
    {
        ll now = original;
        int l = i;
        int r = i + 1;
        while (l >= 0 && r < N)
        {
            now -= a[l] * b[l];
            now -= a[r] * b[r];
            now += a[l] * b[r];
            now += a[r] * b[l];
            mx = std::max(mx, now);
            l--;
            r++;
        };
    }

    std::cout << mx << "\n";

    return 0;
}
