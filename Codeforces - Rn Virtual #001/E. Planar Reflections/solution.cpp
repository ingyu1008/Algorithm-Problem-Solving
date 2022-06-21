#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::map<std::pair<int, int>, int> mp;

int get(int k, int n, int tot)
{
    // std::cout << k << " " << n << "\n";
    if (k <= 0)
        return 0;
    if (mp.find({k, n}) != mp.end())
        return mp[{k, n}];
    if (n == 0)
        return 1;
    else
        return mp[{k, n}] = (get(k - 1, tot - n, tot) + get(k, n - 1, tot)) % 1000000007;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        mp.clear();
        int n, k;
        std::cin >> n >> k;

        std::cout << get(k, n, n) << "\n";
    }

    return 0;
}