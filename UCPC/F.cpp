#include <iostream>
#include <vector>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int M, Q;
    std::cin >> M >> Q;

    std::vector<ll> vx(M + 1), vy(M + 1), vxy(M + 1);

    vx[0]++;
    vy[0]++;
    vxy[M]++;

    for (int i = 0, d, l; i < Q; i++)
    {
        std::cin >> d >> l;
        if (d == 0)
        {
            vy[l]++;
        }
        else if (d == 60)
        {
            vx[l]++;
        }
        else if (d == 120)
        {
            vxy[l]++;
        }
    }

    for (int i = 1; i <= M; i++)
    {
        vx[i] += vx[i - 1];
        vy[i] += vy[i - 1];
        vxy[i] += vxy[i - 1];
    }

    ll ans = 0;

    for (int i = 1; i <= M; i++)
    {
        if(vxy[i] > vxy[i-1]){
            ans += vx[i-1]*vy[i-1];
        }
    }

    std::cout << ans  << "\n";

    return 0;
}