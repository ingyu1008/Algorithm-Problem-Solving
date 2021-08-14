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

#define deb(x) #x << " " << x

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

#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

struct Point
{
    ll x, y, dx = 0, dy = 0;
    bool operator<(const Point &p)
    {
        if (dx * p.dy != dy * p.dx)
        {
            return dx * p.dy > dy * p.dx;
        }
        if (y != p.y)
            return y < p.y;
        return x < p.x;
    }
};

std::vector<Point> pa;
std::vector<Point> CHa;
std::vector<Point> pb;
std::vector<Point> CHb;

ll ccw(const Point &p1, const Point &p2, const Point &p3)
{
    ll temp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    else
        return -1;
}

int f(const Point &A, const Point &B, const Point &C, const Point &D)
{
    return (ccw(A, B, C) * ccw(A, B, D) < 0) && (ccw(C, D, A) * ccw(C, D, B) < 0);
}

bool g(const Point &x, std::vector<Point> &ch)
{
    return ((ch[0].y - ch[1].y) * (ch[0].x - x.x) == (ch[0].y - x.y) * (ch[0].x - ch[1].x)) && ((ch[0].x - x.x) * (ch[1].x - x.x) < 0);
}

bool inside(const Point &x, std::vector<Point> &ch)
{
    int cnt = 0;
    Point y = {x.x + 1, x.y + 10000001};
    for (int i = 0; i < ch.size(); i++)
    {
        cnt += f(x, y, ch[i], ch[(i + 1) % ch.size()]);
    }
    return cnt % 2;
    return false;
}

bool inside2()
{
    int x = 0;
    for (int i = 0; i < CHa.size(); i++)
    {
        for (int j = 0; j < CHb.size(); j++)
        {
            x += f(CHa[i], CHa[(i + 1) % CHa.size()], CHb[j], CHb[(j + 1) % CHb.size()]);
            x += f(CHa[i], CHa[(i + 1) % CHa.size()], CHb[(j + 1) % CHb.size()], CHb[j]);
        }
    }
    return x > 0;
}

int main(void)
{

    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        pa.clear();
        pb.clear();
        CHa.clear();
        CHb.clear();
        int N, M;
        std::cin >> N >> M;

        if (N == 1)
        {
            int x, y;
            std::cin >> x >> y;
            CHa.push_back({x, y, 0, 0});
        }
        else
        {
            for (int i = 0, x, y; i < N; i++)
            {
                std::cin >> x >> y;
                pa.push_back({x, y});
            }
            std::sort(pa.begin(), pa.end());
            for (int i = 0; i < N; i++)
            {
                pa[i].dx = pa[i].x - pa[0].x;
                pa[i].dy = pa[i].y - pa[0].y;
            }
            std::sort(pa.begin(), pa.end());
            CHa.push_back(pa[0]);
            CHa.push_back(pa[1]);
            for (int i = 2; i < N; i++)
            {
                while (CHa.size() >= 2)
                {
                    if (ccw(CHa[CHa.size() - 2], CHa[CHa.size() - 1], pa[i]) > 0)
                    {
                        break;
                    }
                    else
                    {
                        CHa.pop_back();
                    }
                }
                CHa.push_back(pa[i]);
            }
        }

        if (M == 1)
        {
            int x, y;
            std::cin >> x >> y;
            CHb.push_back({x, y, 0, 0});
        }
        else
        {
            for (int i = 0, x, y; i < M; i++)
            {
                std::cin >> x >> y;
                pb.push_back({x, y});
            }
            std::sort(pb.begin(), pb.end());
            for (int i = 0; i < M; i++)
            {
                pb[i].dx = pb[i].x - pb[0].x;
                pb[i].dy = pb[i].y - pb[0].y;
            }
            std::sort(pb.begin(), pb.end());
            CHb.push_back(pb[0]);
            CHb.push_back(pb[1]);
            for (int i = 2; i < M; i++)
            {
                while (CHb.size() >= 2)
                {
                    if (ccw(CHb[CHb.size() - 2], CHb[CHb.size() - 1], pb[i]) > 0)
                    {
                        break;
                    }
                    else
                    {
                        CHb.pop_back();
                    }
                }
                CHb.push_back(pb[i]);
            }
        }

        if (N * M == 0 || (CHa.size() == 1 && CHb.size() == 1))
        {
            std::cout << "YES\n";
            continue;
        }

        if (CHa.size() == 1 && CHb.size() == 2)
        {
            if (g(CHa[0], CHb))
            {
                std::cout << "NO\n";
            }
            else
            {
                std::cout << "YES\n";
            }
            continue;
        }

        if (CHa.size() == 2 && CHb.size() == 1)
        {
            if (g(CHb[0], CHa))
            {
                std::cout << "NO\n";
            }
            else
            {
                std::cout << "YES\n";
            }
            continue;
        }

        bool ans = !inside2();

        for (Point x : CHa)
        {
            ans &= !inside(x, CHb);
        }

        for (Point x : CHb)
        {
            ans &= !inside(x, CHa);
        }

        std::cout << ((ans) ? "YES\n" : "NO\n");
    }

    return 0;
}
