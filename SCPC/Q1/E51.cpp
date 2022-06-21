#include <iostream>

int par[1 << 18];

int find(int a)
{
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    par[a] = b;
}

void init()
{
    for (int i = 0; i <= 100000; i++)
    {
        par[i] = i;
    }
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++)
    {
        init();
        std::cout << "Case #" << t << "\n";

        int N, K;
        std::cin >> N >> K;
        for (int i = 0, a, b, c, d; i < K; i++)
        {
            std::cin >> a >> b >> c;
            if (a == 1)
            {
                std::cin >> d;
                uni(b,c);
            }
            else
            {
                if(find(b) == find(c)){
                    std::cout << 0 << "\n";
                } else {
                    std::cout << "NC\n";
                }
            }
        }
    }
    return 0;
}