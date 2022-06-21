#include <iostream>

bool isVowel[26];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    isVowel['A'- 'A'] = true;
    isVowel['E'- 'A'] = true;
    isVowel['I'- 'A'] = true;
    isVowel['O'- 'A'] = true;
    isVowel['U'- 'A'] = true;

    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << ": ";
        std::string s;
        std::cin >> s;
        int mn = 1e9;
        for(int c = 0; c < 26; c++){
            int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == 'A' + c) continue;
                if(isVowel[s[i] - 'A'] == isVowel[c]){
                    cnt+= 2;
                } else {
                    cnt ++;
                }
            }
            mn = std::min(mn, cnt);
        }
        std::cout << mn << "\n";
    }

    return 0;
}