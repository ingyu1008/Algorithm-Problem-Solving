/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<pii> vpii;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
        b = (b * a) % mod;
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        a ^= b ^= a ^= b;
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

/********************************************************************
						End Of Template
********************************************************************/

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M, K;
        std::cin >> N >> M >> K;

        std::vector<ll> x(N), y(M);

        for (int i = 0; i < N; i++)
        {
            std::cin >> x[i];
        }

        for (int i = 0; i < M; i++)
        {
            std::cin >> y[i];
        }

        std::vector<std::pair<ll, ll>> vx(K), vy(K);

        for (int i = 0; i < K; i++)
        {
            std::cin >> vx[i].first >> vx[i].second;
            vy[i].first = vx[i].second;
            vy[i].second = vx[i].first;

            int xidx = std::lower_bound(x.begin(), x.end(), vx[i].first) - x.begin();
            int yidx = std::lower_bound(y.begin(), y.end(), vy[i].first) - y.begin();
            vx[i].first = 2 * xidx - (vx[i].first != x[xidx]);
            vy[i].first = 2 * yidx - (vy[i].first != y[yidx]);
        }
        std::sort(vx.begin(), vx.end());

        // for(int i = 0; i < K; i++){
        //     std::cout << vx[i].first << " " << vx[i].second << "\n";
        // }
        // std::cout << "\n";

        std::sort(vy.begin(), vy.end());

        ll ans = 0;

        for (int i = 0, j = 0; i < N && j < K; i++)
        {
            ll cnt = 0;
            ll cnt2 = 0;
            ll prevy = -1;
            while (j < K && vx[j].first < 2 * i)
            {
                if (vx[j].second != prevy)
                {
                    cnt += cnt2;
                    cnt2 = 0;
                    prevy = vx[j].second;
                }
                ans += cnt;
                cnt2++;
                j++;
            }
            while (j < K && vx[j].first == 2 * i)
            {
                j++;
            }
        }

        for (int i = 0, j = 0; i < M && j < K; i++)
        {
            ll cnt = 0;
            ll cnt2 = 0;
            ll prevx = -1;
            while (j < K && vy[j].first < 2 * i)
            {
                if (vy[j].second != prevx)
                {
                    cnt += cnt2;
                    cnt2 = 0;
                    prevx = vy[j].second;
                }
                ans += cnt;
                cnt2++;
                j++;
            }
            while (j < K && vy[j].first == 2 * i)
            {
                j++;
            }
        }
        std::cout << ans << "\n";
    }

    return 0;
}
