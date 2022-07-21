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
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    for(int t = 1; t <= T; t++){
        print_tc(t);
        
        int N;
        std::cin >> N;

        std::map<ll, std::vector<ll>> PX, PY;
        ll a, b;
        for(int i = 0; i < N; i++){
            std::cin >> a >> b;
            PX[a].push_back(b);
            PY[b].push_back(a);
        }

        ll x, y;
        for(auto it = PX.begin(); it != PX.end(); it++){
            if(it->second.size() & 1){
                x = it->first;
                break;
            }
        }

        for(auto it = PY.begin(); it != PY.end(); it++){
            if(it->second.size() & 1){
                y = it->first;
                break;
            }
        }

        ll ans = 0;

        for(auto it = PX.begin(); it != PX.end(); it++){
            std::sort(it->second.begin(), it->second.end());
            bool flag = false;
            ll z = 0;
            for(int i = 0; i < it->second.size(); i++){
                if(it->second[i] == y && it->first == x) continue;
                if(!flag) z = it->second[i];
                else ans += it->second[i] - z;
                flag ^= true;
            }
        }

        for(auto it = PY.begin(); it != PY.end(); it++){
            std::sort(it->second.begin(), it->second.end());
            bool flag = false;
            ll z = 0;
            for(int i = 0; i < it->second.size(); i++){
                if(it->second[i] == x && it->first == y) continue;
                if(!flag) z = it->second[i];
                else ans += it->second[i] - z;
                flag ^= true;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}
