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

    int N, M;
    std::cin >> N >> M;

    int first[2] = {202020, 202020};
    int last[2] = {-1, -1};

    std::vector<int> S(N), T(M);

    for (int i = 0; i < N; i++)
    {
        std::cin >> S[i];
        first[S[i]] = std::min(first[S[i]], i);
        last[S[i]] = std::max(last[S[i]], i);
    }

    int cur = S[0];
    int ans = 0;
    bool moved = false;
    bool impossible = false;

    for (int i = 0; i < M; i++)
    {
        std::cin >> T[i];
        if (T[i] == cur)
            ans++;
        else if (moved)
        {
            ans += 2;
            cur = T[i];
        }
        else if (first[T[i]] > N)
        {
            impossible = true;
            break;
        }
        else
        {
            moved = true;
            ans += std::min(N - last[T[i]], first[T[i]]) + 1;
            cur = T[i];
        }
    }

    if (impossible)
    {
        std::cout << "-1\n";
        return 0;
    }

    std::cout << ans << "\n";

    return 0;
}
