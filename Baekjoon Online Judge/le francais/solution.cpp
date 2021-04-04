#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cctype>
#include <cwchar>

std::string nums[1001];

std::string get(int n, int pure = false)
{
    if (n == 7)
    {
        std::cerr << "7";
    }

    if (n == 1001)
    {
        return "mille un";
    }

    if (n == 80)
    {
        return "quatre vingts";
    }

    if (n % 10 == 1 && n > 11)
    {
        if (n < 70)
        {
            return nums[n - n % 10] + " et un";
        }
        else if (n == 81)
        {
            return nums[80] + " un";
        }
        else if (n == 71)
        {
            return nums[60] + " et onze";
        }
        else if (n == 91)
        {
            return nums[80] + " onze";
        }
    }

    if (n == 0)
        if (pure)
            return nums[n];
        else
            return "";
    else if (n <= 19)
        return nums[n];
    else if (n <= 60)
        return nums[n - n % 10] + " " + get(n % 10);
    else if (n < 80)
        return nums[60] + " " + get(n - 60);
    else if (n < 100)
        return nums[80] + " " + get(n - 80);
    else if (n < 200)
        return nums[100] + " " + get(n - 100);
    else if (n < 1000)
        if (n % 100)
            return nums[n / 100] + " " + nums[100] + " " + get(n % 100);
        else
            return nums[n / 100] + " " + nums[100] + "s";
    else
        std::cerr << "invalid";
}

int main(void)
{
    nums[0] = "zero";
    nums[1] = "un";
    nums[2] = "deux";
    nums[3] = "trois";
    nums[4] = "quatre";
    nums[5] = "cinq";
    nums[6] = "six";
    nums[7] = "sept";
    nums[8] = "huit";
    nums[9] = "neuf";
    nums[10] = "dix";
    nums[11] = "onze";
    nums[12] = "douze";
    nums[13] = "treize";
    nums[14] = "quatorze";
    nums[15] = "quinze";
    nums[16] = "seize";
    nums[17] = "dix sept";
    nums[18] = "dix huit";
    nums[19] = "dix neuf";
    //0 ~ 19 : 호출

    nums[20] = "vingt";
    nums[30] = "trente";
    nums[40] = "quarante";
    nums[50] = "cinquante";
    nums[60] = "soixante";
    //20 ~ 60 : 십의자리 일의자리
    //61 - 79 : soixante 나머지

    nums[80] = "quatre vingt";
    //80 ~ 99 : 80-나머지

    nums[100] = "cent";
    //100~199 : cent 나머지
    //200~999 : 숫자 cent 나머지

    std::wstring input;

    std::string s = "abcdefghijklmnopqrstuvxyzÂĂ";

    int res = 0;
    while (std::wcin >> input)
    {
        for (wchar_t c : input)
        {
            if(s.find(c) != s.npos){
                res++;
            }
            // std::wcout << (wchar_t)c << "(" << res << ") ";
        }
        // res += ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    }

    // std::wcout << res << "\n";

    int ans = res - (res % 7) + (res % 7 >= 4) * 7;

    // std::ofstream fout;
    // fout.open("out.txt");

    // for (int i = 0; i <= 1001; i += 7)
    // {
    //     fout << get(i, true) << " " << i << "\n";
    // }
    // fout.close();

    if (ans)
    {
        std::string s = get(ans, true);
        if (s[s.size() - 1] == ' ')
        {
            s = s.substr(0, s.size() - 1);
        }

        std::cout << s << "\n";
    }
    else
    {
        std::wcout << "zero\n";
    }
    return 0;
}