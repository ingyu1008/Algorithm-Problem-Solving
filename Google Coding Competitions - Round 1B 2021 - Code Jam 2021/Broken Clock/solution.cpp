//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

void out(ll h, ll m, ll s, ll n)
{
    std::cout << h << " " << m << " " << s << " " << n << "\n";
}

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cout << "Case #" << t << ": ";
        ll A, B, C;
        std::cin >> A >> B >> C;

        const ll goo = 1e9;
        const ll rev = 43200000000000;

        for (int h = 0; h < 12; h++)
        {
            for (int m = 0; m < 60; m++)
            {
                for (int s = 0; s < 60; s++)
                {
                    std::vector<std::pair<ll, ll>> v(3);
                    v[0].first = (h * 3600 + m * 60 + s) * (goo);
                    v[0].second = goo;

                    v[1].first = (m * 60 + s) * (goo * 12);
                    v[1].second = 12 * goo;

                    v[2].first = s * (goo * 720);
                    v[2].second = 720 * goo;

                    std::sort(v.begin(), v.end());

                    ll AA = (std::abs(v[0].first - A) % rev + rev) % rev;
                    ll BB = (std::abs(v[1].first - B) % rev + rev) % rev;
                    ll CC = (std::abs(v[2].first - C) % rev + rev) % rev;

                    // if (h == 0 && m == 0 && s == 0)
                    // {
                    //     std::cout << AA << " " << BB << " " << CC << "\n";
                    // }

                    if (AA == BB && BB == CC)
                    {
                        if (v[0].second == goo)
                        {
                            out(h, m, s, (v[0].first + AA) % goo);
                            goto found;
                        }
                        else if (v[1].second == goo)
                        {
                            out(h, m, s, (v[1].first + AA) % goo);
                            goto found;
                        }
                        else if (v[2].second == goo)
                        {
                            out(h, m, s, (v[2].first + AA) % goo);
                            goto found;
                        }
                    }
                }
            }
        }

        // //Case 1
        // {
        //     ll total = A;
        //     ll bb = ((total % rev/12) * 12) % (360 * 120 * goo);
        //     ll cc = ((total % rev/12/60) * 720) % (360 * 120 * goo);

        //     if (B - (B % 12) == bb && C - (C % 720) == cc)
        //     {
        //         out((A / rev/12) % 12, (B / rev/720) % 60, (C / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        //     else if (B - (B % 720) == cc && C - (C % 12) == bb)
        //     {
        //         out((A / rev/12) % 12, (C / rev/720) % 60, (B / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        // }
        // //Case 2
        // {
        //     ll total = B;
        //     ll aa = ((total % rev/12) * 12) % (360 * 120 * goo);
        //     ll cc = ((total % rev/720) * 720) % (360 * 120 * goo);

        //     if (A - (A % 12) == aa && C - (C % 720) == cc)
        //     {
        //         out((B / rev/12) % 12, (A / rev/720) % 60, (C / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        //     else if (A - (A % 720) == cc && C - (C % 12) == aa)
        //     {
        //         out((B / rev/12) % 12, (C / rev/720) % 60, (A / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        // }
        // //Case 3
        // {
        //     ll total = C;
        //     ll aa = ((total % rev/12) * 12) % (360 * 120 * goo);
        //     ll bb = ((total % rev/720) * 720) % (360 * 120 * goo);

        //     if (A - (A % 12) == aa && B - (B % 720) == bb)
        //     {
        //         out((C / rev/12) % 12, (A / rev/720) % 60, (B / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        //     else if (A - (A % 720) == bb && B - (B % 12) == aa)
        //     {
        //         out((C / rev/12) % 12, (B / rev/720) % 60, (A / rev/720/60) % 60, (A / goo) % (goo));
        //         goto found;
        //     }
        // }
    found:
        t = t;
    }

    return 0;
}
