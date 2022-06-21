/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#define private public
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <x86intrin.h>

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

// ref: https://gist.github.com/cgiosy/a441de545c9e96b1d7b02cc7a00561f9?fbclid=IwAR0N3Woe8GwzAsxMapbEE9b7rrE_XArl50BRdQ9ZOTCxk-2X5BRrm-HBVpo
namespace std {
    template<size_t _Nw> void _M_do_sub(_Base_bitset<_Nw>& A, const _Base_bitset<_Nw>& B) {
        for (int i = 0, c = 0; i < _Nw; i++)
            c = _subborrow_u64(c, A._M_w[i], B._M_w[i], (unsigned long long*) & A._M_w[i]);
    }
    template<> void _M_do_sub(_Base_bitset<1>& A, const _Base_bitset<1>& B) {
        A._M_w -= B._M_w;
    }
    template<size_t _Nb> bitset<_Nb>& operator-=(bitset<_Nb>& A, const bitset<_Nb>& B) {
        _M_do_sub(A, B);
        return A;
    }
    template<size_t _Nb> inline bitset<_Nb> operator-(const bitset<_Nb>& A, const bitset<_Nb>& B) {
        bitset<_Nb> C(A);
        return C -= B;
    }
}

// ref: http://www.secmem.org/blog/2019/09/12/lcs-with-bitset/
int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::string A, B;
    std::cin >> A >> B;

    std::bitset<50000> S[26], x, D;
    for (int i = 0; i < B.size(); i++)
        S[B[i] - 'A'].set(i);

    for (int i = 0; i < A.size(); i++) {
        x = S[A[i] - 'A'] | D;
        D = (D << 1).set(0);
        D = x & (x ^ (x - D));
    }

    std::cout << D.count() << '\n';

    return 0;
}
