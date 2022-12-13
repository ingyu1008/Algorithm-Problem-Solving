#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

typedef long long ll;

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> v(N + 1);

    for (int i = 1; i <= N; i++)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    std::vector<int> vv;
    for (int i = 1; i <= N; i++)
    {
        if (vv.empty() || vv.back() != v[i])
        {
            vv.push_back(v[i]);
        }
        else
        {
            vv.pop_back();
        }
    }

    int Q;
    std::cin >> Q;
    int cnt = 0;
    std::map<std::pair<int, int>, int> mp;
    while (Q--)
    {
        int l, r;
        int res = 0;
        std::cin >> l >> r;
        int ll = std::upper_bound(vv.begin(), vv.end(), l) - vv.begin();
        int rr = std::upper_bound(vv.begin(), vv.end(), r) - vv.begin() - 1;
        if (vv[ll] == vv[rr])
            res = (rr - ll + 1) % 2;
        else
        {
            if (mp.find({l, r}) != mp.end())
            {
                res = mp[{l, r}];
            }
            else
            {
                for (int i = ll; i <= rr; i++)
                {
                    res ^= (vv[i] - l);
                }
                mp[{l, r}] = res;
            }
        }
        if (res)
        {
            std::cout << "A";
        }
        else
        {
            std::cout << "B";
        }
    }

    return 0;
}