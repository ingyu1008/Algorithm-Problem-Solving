#include <iostream>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    int L, R;
    std::cin >> L >> R;
    
    std::string S;
    std::cin >> S;

    for(int i = 1; i <= S.size(); i++){
        if(i >= L && i <= R){
            std::cout << S[L + R - i - 1];
        } else {
            std::cout << S[i - 1];
        }
    }

    std::cout << "\n";
    
    return 0;
}