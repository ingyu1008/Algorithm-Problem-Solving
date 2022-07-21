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
ll dp[1010101][1 << 3];

ll map[3030303];

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int T;
    std::cin >> T;

    while(T--){
        int N;
        std::cin >> N;

        std::vector<int> A(N), B(N), sortedA(N), sortedB(N);

        for(int i = 0; i < N; i++){
            std::cin >> A[i];
            sortedA[i] = A[i];
        }
        
        for(int i = 0; i < N; i++){
            std::cin >> B[i];
            sortedB[i] = B[i];
        }

        std::sort(sortedA.begin(), sortedA.end());
        std::sort(sortedB.begin(), sortedB.end());

        bool diff = false;
        for(int i = 0; i < N; i++){
            if(sortedA[i] != sortedB[i]) diff = true;
        }

        if(diff){
            std::cout << "No\n";
        } else {
            std::vector<std::pair<int, int>> ans;
            for(int i = 0; i < N; i++){
                if(A[i] == B[i]) continue;
                for(int j = i+1; j < N; j++){
                    if(A[i] == B[j]){
                        if(j - i <= 2){
                            ans.emplace_back(i, j);
                        } else {
                            ans.emplace_back(i, j);
                            ans.emplace_back(i+1, j-1);
                        } 
                    }
                }
            }

            if(ans.size() > N*N){
                std::cout << "No\n";
            } else {
                std::cout << "Yes\n";

            std::cout << ans.size() << "\n";
            for(auto p : ans){
                std::cout << p.first << " " << p.second << "\n";
            }
            }
        }
    }

    return 0;
}
