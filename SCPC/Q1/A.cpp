#include <iostream>
#include <set>

int par[1 << 17];

void init(int N)
{
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
    }
}

int find(int node)
{
    if (par[node] == node)
        return node;
    return par[node] = find(par[node]);
}

void uni(int a, int b)
{
    int aa = find(a);
    int bb = find(b);
    if (aa == bb)
        return;
    if (aa > bb)
        std::swap(aa, bb);
    par[bb] = aa;
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int N;
        std::cin >> N;

        init(N);

        for(int i = 0, x; i < N; i++){
            std::cin >> x;
            if(i + x >= N) continue;
            uni(i, i+x);
        }

        std::set<int> st;

        for(int i = 0; i < N; i++){
            st.insert(find(i));
        }
        
        std::cout << "Case #" << t << "\n";
        std::cout << st.size() << "\n";
    }

    return 0;
}