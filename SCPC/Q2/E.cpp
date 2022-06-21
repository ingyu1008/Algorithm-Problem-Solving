#include <iostream>

void parse(int from, int to)
{
    if (from == 1)
    {
        std::cout << ((to == 2) ? "A" : "B");
    }
    if (from == 2)
    {
        std::cout << ((to == 1) ? "C" : "D");
    }
    if (from == 3)
    {
        std::cout << ((to == 1) ? "E" : "F");
    }
}

void solve(int N, int from, int to)
{
    // strategy : move smallest then largest and so on

    if (N == 0)
        return;
    if (N == 1)
    {
        parse(from, to);
        return;
    }
    solve(N - 2, from, 6 - from - to); // except the smallest
    parse(from, to);                   // move the smallest
    solve(N - 2, 6 - from - to, from); // except the largest
    parse(6 - from - to, to);          // move the largest
    solve(N - 2, from, to);            // move everything
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    int M;
    std::cin >> M;

    std::cout << "Case #1\n";
    std::cout << "6\n";

    // solve(2, 1, 3);

    parse(1,3);
    parse(1,2);
    parse(3,2);

    parse(1,3);
    parse(2,1);
    parse(3,2);
    parse(1,2);
    parse(1,3);
    parse(2,1);
    parse(2,3);
    parse(2,3);
    parse(1,3);
    parse(1,2);

    parse(3,1);
    parse(3,1);
    parse(1,2);
    parse(1,2);
    parse(3,1);
    parse(2,1);
    parse(2,3);
    parse(1,3);
    parse(2,1);

    return 0;
}