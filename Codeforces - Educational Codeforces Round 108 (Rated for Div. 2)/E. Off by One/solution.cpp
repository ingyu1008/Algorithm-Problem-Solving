#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define pa points[i].first.first
#define pb points[i].first.second
#define pc points[i].second.first
#define pd points[i].second.second

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b % a, a);
}

struct comparator
{
    bool operator()(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) const
    {
        if (a.second * b.first != a.first * b.second)
            return a.second * b.first < a.first * b.second;
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::map<std::pair<ll, ll>, std::set<int>, comparator> mp;
    std::vector<std::pair<std::pair<ll, ll>, std::pair<ll, ll>>> points(N);

    ll x, y, g;
    for (int i = 0; i < N; i++)
    {
        std::cin >> pa >> pb >> pc >> pd;

        x = (pa + pb) * pd;
        y = (pc)*pb;
        g = gcd(x, y);
        mp[{x / g, y / g}].insert(i);

        x = (pa)*pd;
        y = (pc + pd) * pb;
        g = gcd(x, y);
        mp[{x / g, y / g}].insert(i);
    }

    ll cnt = 0;

    std::vector<std::pair<int, int>> ans;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        while (it->second.size() >= 2)
        {
            int xx = *(it->second.rbegin());
            it->second.erase(*it->second.rbegin());
            int yy = *(it->second.rbegin());
            it->second.erase(*it->second.rbegin());
            ans.push_back({xx, yy});

            x = (points[xx].first.first + points[xx].first.second) * points[xx].second.second;
            y = (points[xx].second.first) * points[xx].first.second;
            g = gcd(x, y);
            mp[{x / g, y / g}].erase(xx);

            x = (points[yy].first.first + points[yy].first.second) * points[yy].second.second;
            y = (points[yy].second.first) * points[yy].first.second;
            g = gcd(x, y);
            mp[{x / g, y / g}].erase(yy);

            x = (points[xx].first.first) * points[xx].second.second;
            y = (points[xx].second.first + points[xx].second.second) * points[xx].first.second;
            g = gcd(x, y);
            mp[{x / g, y / g}].erase(xx);

            x = (points[yy].first.first) * points[yy].second.second;
            y = (points[yy].second.first + points[yy].second.second) * points[yy].first.second;
            g = gcd(x, y);
            mp[{x / g, y / g}].erase(yy);

            cnt++;
        }
    }

    std::cout << cnt << "\n";

    for (int i = 0; i < cnt; i++)
    {
        std::cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

    return 0;
}
