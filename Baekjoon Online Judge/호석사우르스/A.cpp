#include <iostream>

bool led[6][7];

int parseLed(bool x[7])
{
    if (x[0] && x[1] && x[2] && x[3] && x[4] && x[5] && x[6])
        return 8;
    if (x[0] && x[1] && x[2] && x[4] && x[5] && x[6])
        return 0;
    if (x[0] && x[1] && x[3] && x[4] && x[5] && x[6])
        return 6;
    if (x[0] && x[1] && x[2] && x[3] && x[5] && x[6])
        return 9;
    if (x[0] && x[2] && x[3] && x[4] && x[6])
        return 2;
    if (x[0] && x[2] && x[3] && x[5] && x[6])
        return 3;
    if (x[0] && x[1] && x[3] && x[5] && x[6])
        return 5;
    if (x[1] && x[2] && x[3] && x[5])
        return 4;
    if (x[0] && x[2] && x[5])
        return 7;
    if (x[2] && x[5])
        return 1;
    return -1;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, K, P, X;
    std::cin >> N >> K >> P >> X;

    return 0;
}