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

int isPrime[1010101];
std::vector<bool> w[6];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    for (int i = 0; i < 6; i++)
    {
        w[i].resize(1010101);
    }

    std::fill_n(isPrime, 1010101, true);
    isPrime[1] = false;

    for (ll i = 2; i * i <= 1000000; i++)
    {
        if (!isPrime[i])
            continue;
        for (ll j = i + i; j <= 1000000; j+=i)
        {
            isPrime[j] = false;
        }
    }

    for (ll i = 1; i <= 1e6; i++)
    {
        w[0][i] = isPrime[i];
        if (i <= 1e3)
            w[1][i * i] = true;
        if (i <= 1e2)
            w[2][i * i * i] = true;
        if (i * i <= 1e3)
            w[3][i * i * i * i] = true;

        ll sum = 0;
        ll prod = 1;
        ll j = i;
        while (j)
        {
            sum += j % 10;
            prod *= j % 10;
            j /= 10;
        }

        if (sum <= 1e6 && sum > 0 && (i % sum) == 0)
            w[4][i] = true;
        if (prod <= 1e6 && prod > 0 &&  (i % prod) == 0)
            w[5][i] = true;
    }

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cout << "DATA SET #" << t << "\n";

        int N;
        std::cin >> N;

        std::vector<ll> v(N);
        std::vector<bool> x[7];
        for (int i = 0; i < 7; i++)
        {
            x[i].clear();
            x[i].resize(1010101);
        }

        for (int i = 0; i < N; i++)
        {
            std::cin >> v[i];
        }
        std::sort(v.begin(), v.end());

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                if (v[j] % v[i] == 0)
                    x[0][v[i]] = true;
                if (v[i] % v[j] == 0)
                    x[1][v[i]] = true;
                if (v[j] <= 1e3 && v[i] == v[j] * v[j])
                    x[2][v[i]] = true;
                if (v[j] <= 1e2 && v[i] == v[j] * v[j] * v[j])
                    x[3][v[i]] = true;
                if (v[j] * v[j] <= 1e3 && v[i] == v[j] * v[j] * v[j] * v[j])
                    x[4][v[i]] = true;

                ll sum = 0;
                ll prod = 1;
                ll k = v[j];
                while (k)
                {
                    sum += k % 10;
                    prod *= k % 10;
                    k /= 10;
                }

                if (sum <= 1e6 && sum > 0 && (v[i] % sum) == 0)
                    x[5][v[i]] = true;
                if (prod <= 1e6 && prod > 0 && (v[i] % prod) == 0)
                    x[6][v[i]] = true;
            }
        }

        int mx = 0;
        for (auto i : v)
        {
            int cnt = 0;
            for (int j = 0; j < 6; j++)
            {
                cnt += w[j][i];
            }
            for (int j = 0; j < 7; j++)
            {
                cnt += x[j][i];
            }
            mx = std::max(mx, cnt);
            // std::cout << i << " " << cnt << "\n";
        }

        for (auto i : v)
        {
            int cnt = 0;
            for (int j = 0; j < 6; j++)
            {
                cnt += w[j][i];
            }
            for (int j = 0; j < 7; j++)
            {
                cnt += x[j][i];
            }
            if (cnt == mx)
            {
                std::cout << i << "\n";
            }
        }
    }

    return 0;
}
