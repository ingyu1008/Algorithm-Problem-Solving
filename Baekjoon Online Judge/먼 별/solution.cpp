//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;

class Point
{
private:
    ll x, y, dx = 0, dy = 0;
    static ll pivotX, pivotY;

public:
    Point(ll _x, ll _y) : x(_x), y(_y)
    {
        Point::updatePivot(*this);
    }

    static void updatePivot(Point &p)
    {
        if (p.y < pivotY)
        {
            pivotY = p.y;
            pivotX = p.x;
        }
        else if (p.y == pivotY && p.x < pivotX)
        {
            pivotX = p.x;
        }
    }

    Point getDiff(Point &p1, Point &p2)
    {
        return Point(p2.x - p1.x, p2.y - p1.y);
    }
    void calculateDxDy()
    {
        dx = x - pivotX;
        dy = y - pivotY;
    }

    bool operator<(const Point &p)
    {
        //second sort
        if (dx * p.dy != dy * p.dx) // not on a single line
        {
            return dy * p.dx < dx * p.dy; // order by dy/dx asc
        }
        // first sort (to find pivot point)
        if (y != p.y)
            return y < p.y; // order by y asc
        return x < p.x;     // order by x asc
    }

    friend int ccw(const Point &p1, const Point &p2, const Point &p3);
    friend int ccw(const Point &v1, const Point &v2);
    friend ll dist(const Point &p1, const Point &p2);
    friend Point operator-(const Point &p1, const Point &p2);
};

ll Point::pivotX = 1e18;
ll Point::pivotY = 1e18;

int ccw(const Point &p1, const Point &p2, const Point &p3)
{
    ll temp = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if (temp > 0)
        return 1;
    else if (temp == 0)
        return 0;
    else
        return -1;
}

int ccw(std::pair<ll, ll> &p1, std::pair<ll, ll> &p2, std::pair<ll, ll> &p3)
{
    return ccw(Point(p1.first, p1.second), Point(p2.first, p2.second), Point(p3.first, p3.second));
}
int ccw(Point &p1, Point &p2, std::pair<ll, ll> &p3)
{
    return ccw(p1, p2, Point(p3.first, p3.second));
}

int ccw(const Point &v1, const Point &v2)
{
    return ccw(v1, Point(0, 0), v2);
}

ll dist(const Point &p1, const Point &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

ll dist(const std::pair<ll, ll> &p1, const std::pair<ll, ll> &p2)
{
    return dist(Point(p1.first, p1.second), Point(p2.first, p2.second));
}

Point operator-(const Point &p1, const Point &p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}

std::vector<std::pair<ll, ll>> p;
bool cmp(std::pair<ll, ll> o1, std::pair<ll, ll> o2)
{
    int c = ccw(p[0], o1, o2);
    if (c)
        return c > 0;
    return dist(p[0], o1) < dist(p[0], o2);
}

class ConvexHull
{
private:
    std::vector<Point> CH;

public:
    void init()
    {
        CH.clear();
        p.clear();
    }

    void addPoint(ll _x, ll _y)
    {
        p.push_back({_x, _y});
    }

    void createConvexHull()
    {
        std::sort(p.begin(), p.end());
        std::sort(p.begin() + 1, p.end(), cmp);
        CH.clear();

        // try
        // {
        //     if (points.size() < 3)
        //     {
        //         throw "Exception : NotEnoughPoints";
        //     }
        // }
        // catch (const char *s)
        // {
        //     std::cerr << s << "\n";
        // }

        for (int i = 0; i < p.size(); i++)
        {
            while (CH.size() >= 2)
            {
                if (ccw(CH[CH.size() - 2], CH[CH.size() - 1], p[i]) > 0)
                {
                    break;
                }
                else
                {
                    CH.pop_back();
                }
            }
            CH.push_back(Point(p[i].first, p[i].second));
        }
    }

    std::vector<Point> &getConvexHull()
    {
        return CH;
    }

    ll getMaxDist()
    {
        if (CH.empty())
        {
            createConvexHull();
        }

        if (CH.size() == 1)
            return 0;

        ll max = 0;

        int A = 0;
        int B = 1;
        while (A < CH.size())
        {
            A %= CH.size();
            B %= CH.size();
            int C = (A + 1) % CH.size();
            int D = (B + 1) % CH.size();
            max = std::max(max, dist(CH[A], CH[B]));

            int ccwres = ccw(CH[C] - CH[A], CH[B] - CH[D]);

            if (ccwres == 1)
            {
                B++;
            }
            else
            {
                A++;
            }
        }
        return max;
    }
};

struct Star
{
    ll x, y, dx, dy;
};

std::vector<Star *> v;

ll calc(ll t)
{
    ConvexHull CH;
    CH.init();

    for (int i = 0; i < v.size(); i++)
    {
        CH.addPoint(v[i]->x + v[i]->dx * t, v[i]->y + v[i]->dy * t);
    }

    ll d = CH.getMaxDist();

    // std::cout << "t = " << t << " d*d = " << d << "\n";

    return d;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    ll N;
    std::cin >> N;
    ll T;
    std::cin >> T;

    for (int i = 0; i < N; i++)
    {
        Star *x = new Star;
        std::cin >> x->x >> x->y >> x->dx >> x->dy;
        v.push_back(x);
    }

    ll mn = 9e18;
    ll ans = -1;

    ll l = 0, r = T;
    while (l + 10 < r)
    {
        ll m1 = (2 * l + r) / 3;
        ll m2 = (l + 2 * r) / 3;

        ll dm1 = calc(m1);
        ll dm2 = calc(m2);
        if (dm1 > dm2)
        {
            l = m1;
        }
        else
        {
            r = m2;
        }
    }

    for (int i = l; i <= r; i++)
    {
        ll d = calc(i);
        if (mn > d)
        {
            mn = d;
            ans = i;
        }
    }

    std::cout << ans << "\n"
              << mn;

    return 0;
}