#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    srand(time(NULL));

    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> v(H);

    for (int i = 0; i < H; i++)
    {
        std::cin >> v[i];
    }

    int cnt = v[H-1][W-1] == '*';

    int r = 0;
    int c = 0;

    while (r != H-1 || c != W-1)
    {
        cnt += v[r][c] == '*';
        if(r == H-1){
            c++;
        } else if(c == W-1){
            r++;
        } else if(v[r][c+1] == '*'){
            c++;
        } else if(v[r+1][c] == '*'){
            r++;
        } else {
            c++;
        }
    }

    std::cout << cnt ;

    return 0;
}