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

std::string a, b, ans;

void LCS(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return;
    if (l1 == r1) {
        for (int i = l2; i <= r2; i++)
            if (a[l1] == b[i]) {
                ans += b[i];
                break;
            }
        return;
    }

    int mid = (l1 + r1) / 2;

    std::vector<int> left[2], right[2];

    left[0].resize(r2 - l2 + 3);
    left[1].resize(r2 - l2 + 3);
    right[0].resize(r2 - l2 + 3);
    right[1].resize(r2 - l2 + 3);

    for (int i = l1; i <= mid; i++) {
        for (int j = l2; j <= r2; j++) {
            if (a[i] == b[j]) {
                left[i & 1][j - l2 + 1] = left[(i & 1) ^ 1][j - l2] + 1;
            } else {
                left[i & 1][j - l2 + 1] = std::max(left[i & 1][j - l2], left[(i & 1) ^ 1][j - l2 + 1]);
            }
        }
    }

    for (int i = r1; i > mid; i--) {
        for (int j = r2 + 1; j > l2; j--) {
            if (a[i] == b[j - 1]) {
                right[i & 1][j - l2] = right[(i & 1) ^ 1][j - l2 + 1] + 1;
            } else {
                right[i & 1][j - l2] = std::max(right[i & 1][j - l2 + 1], right[(i & 1) ^ 1][j - l2]);
            }
        }
    }

    int idx = -1;
    for (int i = l2; i <= r2 + 1; i++) {
        if (idx < 0 || left[mid & 1][idx - l2] + right[(mid & 1) ^ 1][idx - l2 + 1] < left[mid & 1][i - l2] + right[(mid & 1) ^ 1][i - l2 + 1])
            idx = i;
    }

    LCS(l1, mid, l2, idx - 1);
    LCS(mid + 1, r1, idx, r2);
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> a >> b;

    LCS(0, a.size() - 1, 0, b.size() - 1);

    int ia = 0, ib = 0, ic = 0;
    while (ic < ans.size()) {
        while (ans[ic] != b[ib]) {
            if (ans[ic] == a[ia]) {
                std::cout << "a " << b[ib++] << "\n";
            } else {
                ia++;
                std::cout << "m " << b[ib++] << "\n";
            }
        }
        while (ans[ic] != a[ia]) {
            std::cout << "d " << a[ia++] << "\n";
        }
        std::cout << "c " << a[ia++] << "\n";
        ib++;
        ic++;
    }
    while (ib < b.size()) {
        if (ia < a.size()) {
            ia++;
            std::cout << "m " << b[ib++] << "\n";
        } else {
            std::cout << "a " << b[ib++] << "\n";
        }
    }
    while (ia < a.size()) {
        std::cout << "d " << a[ia++] << "\n";
    }

    return 0;
}
