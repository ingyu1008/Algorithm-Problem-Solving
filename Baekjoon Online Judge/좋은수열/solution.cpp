#include <iostream>
#include <vector>
#include <algorithm>

std::string res = "";

bool solve(int N)
{
    if (N == 0)
        return true;

    std::string tmp = res;
    bool flag;

    res = tmp + "1";
    flag = true;
    for (int i = 1; flag && i <= res.size() / 2; i++)
    {
        if (res.substr(res.size() - i, i) == res.substr(res.size() - 2 * i, i))
        {
            flag = false;
        }
    }
    if (flag)
    {
        if (solve(N - 1))
            return true;
    }

    res = tmp + "2";
    flag = true;
    for (int i = 1; flag && i <= res.size() / 2; i++)
    {
        if (res.substr(res.size() - i, i) == res.substr(res.size() - 2 * i, i))
        {
            flag = false;
        }
    }
    if (flag)
    {
        if (solve(N - 1))
            return true;
    }

    res = tmp + "3";
    flag = true;
    for (int i = 1; flag && i <= res.size() / 2; i++)
    {
        if (res.substr(res.size() - i, i) == res.substr(res.size() - 2 * i, i))
        {
            flag = false;
        }
    }
    if (flag)
    {
        if (solve(N - 1))
            return true;
    }

    return false;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    solve(N);
    std::cout << res << "\n";

    return 0;
}