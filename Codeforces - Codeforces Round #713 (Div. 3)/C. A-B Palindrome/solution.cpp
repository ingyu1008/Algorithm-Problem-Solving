#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    while (T--)
    {
        int a, b;
        std::cin >> a >> b;
        std::string s;
        std::cin >> s;
        bool valid = true;
        for (int i = 0; i < s.size() / 2; i++)
        {
            int j = s.size() - i - 1;
            if (s[i] == s[j])
            {
                if (s[i] == '0')
                {
                    a -= 2;
                }
                else if (s[i] == '1')
                {
                    b -= 2;
                }
            }
            if (s[i] == '0' && s[j] == '1')
                valid = false;
            if (s[i] == '1' && s[j] == '0')
                valid = false;
            if (s[i] == '0' && s[j] == '?')
            {
                s[j] = '0';
                a -= 2;
            }
            if (s[i] == '1' && s[j] == '?')
            {
                s[j] = '1';
                b -= 2;
            }
            if (s[i] == '?' && s[j] == '0')
            {
                s[i] = '0';
                a -= 2;
            }
            if (s[i] == '?' && s[j] == '1')
            {
                s[i] = '1';
                b -= 2;
            }
        }
        if (s.size() & 1)
        {
            if (s[(s.size()) / 2] == '0')
                a--;
            if (s[(s.size()) / 2] == '1')
                b--;
            if (s[(s.size()) / 2] == '?')
            {
                if (a > 0 && a & 1)
                {
                    a--;
                    s[(s.size()) / 2] = '0';
                }
                else if (b > 0 && b & 1)
                {
                    b--;
                    s[(s.size()) / 2] = '1';
                }
                else
                {
                    valid = false;
                }
            }
        }

        if (a < 0 || b < 0 || a & 1 || b & 1)
            valid = false;

        if (!valid)
        {
        invalid:
            std::cout << "-1\n";
        }
        else
        {
            for (int i = 0; i < s.size() / 2; i++)
            {
                int j = s.size() - i - 1;
                if (s[i] == s[j] && s[i] == '?')
                {
                    if (a >= 2)
                    {
                        a -= 2;
                        s[i] = s[j] = '0';
                    }
                    else if (b >= 2)
                    {
                        b -= 2;
                        s[i] = s[j] = '1';
                    }
                }
            }

            if (s.find('?') != s.npos)
                goto invalid;

            std::cout << s << "\n";
        }
    }

    return 0;
}