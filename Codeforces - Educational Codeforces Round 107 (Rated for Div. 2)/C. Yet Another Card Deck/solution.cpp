#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> a(N);
    int q;
    std::vector<int> v(51, 303030);
    for (int i = 0; i < N; i++)
    {
        std::cin >> a[i];
        v[a[i]] = std::min(v[a[i]], i + 1);
    }

    for (int i = 0; i < Q; i++)
    {
        std::cin >> q;
        std::cout << v[q] << " ";
        for(int j = 1; j <= 50; j++){
            if(v[j] < v[q]){
                v[j]++;
            }
        }
        v[q] = 1;
    }

    return 0;
}