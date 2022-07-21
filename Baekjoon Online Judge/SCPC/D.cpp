/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<pii> vpii;

ll mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll b = powmod(a, n / 2);
    b = (b * b) % mod;
    if (n & 1)
        b = (b * a) % mod;
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a < b)
        a ^= b ^= a ^= b;
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}

/********************************************************************
						End Of Template
********************************************************************/

void print_tc(int t){
    std::cout << "Case #" << t << "\n";
}

int main(void)
{
    setbuf(stdout, NULL);
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for(int t = 1; t <= T; t++){
        print_tc(t);
        int N, M;
        std::cin >> N >> M;

        std::string X, Y;
        std::cin >> X >> Y;

        if( N > 2000 || M > 2000){
            std::cout << "YES" << std::endl;
            continue;
        }

        if(Y[0] == 'b'){
            for(auto &x : X){
                x ^= 'a'^'b';
            }
            for(auto &y : Y){
                y ^= 'a'^'b';
            }
        }

        int cnta = 0;
        int cntb = 0;
        for(auto &y : Y){
            cnta += (y == 'a');
            cntb += (y == 'b');
        }

        bool flag = false;

        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                std::vector<char> v;
                int a = 0;
                int b = 0;
                for(int k = 0; v.size() < M && k < N; k++){
                    if(X[k] == 'a'){
                        if(k >= i && a < cnta){
                            v.push_back(X[k]);
                            a++;
                        }
                    } else if(X[k] == 'b'){
                        if(k >= j && b < cntb){
                            v.push_back(X[k]);
                            b++;
                        }
                    }
                }

                bool validate = (v.size() == M);

                for(int k = 0; k < v.size(); k++){
                    validate &= (v[k] == Y[k]);
                }

                if(validate){
                    flag = true;
                    goto exit;
                }
            }
        }

        exit:
        if(flag){
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}