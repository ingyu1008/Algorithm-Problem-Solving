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
#include <cmath>

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

typedef std::pair<ll, ll> vec;

int ccw(vec a, vec b)
{
    ll res = a.first * b.second - a.second * b.first;
    if (res > 0)
    {
        return 1;
    }
    else if (res < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int ccw_point(vec a, vec b, vec c)
{
    vec ab = {b.first - a.first, b.second - a.second};
    vec bc = {c.first - b.first, c.second - b.second};

    return ccw(ab, bc);
}

vec operator-(const vec &a, const vec &b)
{
    return {a.first - b.first, a.second - b.second};
}

std::vector<vec> v;
vec pivot;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;
    for (int i = 0, x, y; i < N; i++)
    {
        std::cin >> x >> y;
        v.push_back({x, y});
    }

    std::sort(v.begin(), v.end());
    pivot = v[0];

    std::sort(v.begin(), v.end(), [](const vec &a, const vec &b) -> bool
              {
                  vec pa = a - pivot;
                  vec pb = b - pivot;
                  if (pa.second * pb.first != pb.second * pa.first)
                  {
                      return pa.second * pb.first < pb.second * pa.first;
                  }
                  else
                  {
                      return pa.first * pa.first + pa.second * pa.second < pb.first * pb.first + pb.second * pb.second;
                  }
              });

    std::vector<vec> ch;

    ch.push_back(v[0]);
    ch.push_back(v[1]);

    for (int i = 2; i < N; i++)
    {
        while (v.size() >= 2 && ccw_point(ch[ch.size() - 2], ch[ch.size() - 1], v[i]) <= 0)
        {
            ch.pop_back();
        }

        ch.push_back(v[i]);
    }

    std::cout << ch.size() << "\n";

    return 0;
}
