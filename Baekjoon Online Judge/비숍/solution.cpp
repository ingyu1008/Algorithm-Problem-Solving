#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int N;

std::vector<std::vector<int>> v;

bool isDiag(int r, int c, int rr, int cc)
{
    return (r + c == rr + cc) || (r - c == rr - cc);
}

int solve(int r, int c)
{
    int rr = r;
    int cc = c + 2;
    if (cc >= N)
    {
        rr++;
        cc %= N;
        if (N % 2 == 0)
        {
            cc++;
            cc %= 2;
        }
    }

    if (r >= N)
        return 0;

    if (v[r][c] == 1)
    {
        int res = solve(rr, cc);

        std::stack<int> s;
        for (int rrr = 0; rrr < N; rrr++)
        {
            for (int ccc = 0; ccc < N; ccc++)
            {
                if (v[rrr][ccc] == 1 && isDiag(r, c, rrr, ccc))
                {
                    v[rrr][ccc] = 0;
                    s.push(ccc);
                    s.push(rrr);
                }
            }
        }

        res = std::max(res, solve(rr, cc) + 1);
        while (!s.empty())
        {
            int rrrr = s.top();
            s.pop();
            int cccc = s.top();
            s.pop();
            v[rrrr][cccc] = 1;
        }
        return res;
    }
    else
    {
        // std::cout << "v[" << r << "][" << c << "] = " << v[r][c] << "\n";
        return solve(rr, cc);
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++)
    {
        v[i].resize(N);
        for (int j = 0; j < N; j++)
        {
            std::cin >> v[i][j];
        }
    }

    int x = solve(0, 0) + solve(0, 1);

    std::cout << x << "\n";

    return 0;
}