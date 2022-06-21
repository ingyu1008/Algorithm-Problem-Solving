#include <fstream>
#include <vector>

typedef long long ll;

int main(void)
{
    std::ifstream in;
    in.open("input.txt");

    std::ofstream out;
    out.open("output.txt");

    int T;
    in >> T;

    int N;
    std::string s;

    for (int t = 1; t <= T; t++)
    {
        out << "Case #" << t << ": ";

        in >> N >> s;

        ll ans = 0;
        ll diff = 0;
        ll lastXO = 0;
        char lastChar = 'F';

        for (int i = 0; i < N; i++)
        {
            if (s[i] == 'X')
            {
                if (lastChar == 'O')
                {
                    diff += lastXO + 1;
                }
                lastChar = 'X';
                lastXO = i;
            }
            else if (s[i] == 'O')
            {
                if (lastChar == 'X')
                {
                    diff += lastXO + 1;
                }
                lastChar = 'O';
                lastXO = i;
            }
            ans = (ans + diff) % 1000000007;
        }

        out << ans << "\n";
    }

    in.close();
    out.close();
}