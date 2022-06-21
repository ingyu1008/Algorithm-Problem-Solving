#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << "\n";

        ll n, m;
        std::cin >> n >> m;
        ll odd = 0;
        std::vector<std::vector<ll>> vv;
        for (ll i = 0, x; i < n; i++)
        {
            std::cin >> x;
            odd |= (x & 1);
            std::vector<ll> v;
            for (ll j = 0, y; j < x; j++)
            {
                std::cin >> y;
                v.push_back(y);
            }
            std::sort(v.begin(), v.end());
            std::vector<ll> v2;
            v2.push_back(v[0]);
            v2.push_back(v[1]);
            v2.push_back(v[2]);
            v2.push_back(v[3]);
            vv.push_back(v2);
        }

        ll mx = 0;
        ll mx2 = 0;
        ll sm = 0;
        std::vector<ll> vvv;
        for (auto v : vv)
        {
            for (ll i = 0; i < 4; i++)
            {
                sm += v[i];
            }
            ll x = v[2] + v[3];
            if (x > mx)
            {
                mx2 = mx;
                mx = x;
            }
            else if (x > mx2)
            {
                mx2 = x;
            }
        }
        if (odd == 0)
        {
            std::cout << sm - mx - mx2 << "\n";
        }
        else
        {
            std::cout << "0\n";
        }
    }

    return 0;
}