/********************************************************************
Problem Solving / Competitive Programming Template

Code by MatWhyTle(ingyu1008)
********************************************************************/

//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
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

int main(void)
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    while (std::cin >> N)
    {
        std::cin >> M;
        std::vector<int> v[2020];
        std::vector<int> rv[2020];

        int A, B;
        for (int i = 0; i < M; i++)
        {
            std::cin >> A >> B;
            v[abs(A) + (A > 0) * 1000].push_back(abs(B) + (B < 0) * 1000);
            v[abs(B) + (B > 0) * 1000].push_back(abs(A) + (A < 0) * 1000);

            rv[abs(A) + (A < 0) * 1000].push_back(abs(B) + (B > 0) * 1000);
            rv[abs(B) + (B < 0) * 1000].push_back(abs(A) + (A > 0) * 1000);
        }

        A = 1, B = 1;

        v[abs(A) + (A > 0) * 1000].push_back(abs(B) + (B < 0) * 1000);
        v[abs(B) + (B > 0) * 1000].push_back(abs(A) + (A < 0) * 1000);

        rv[abs(A) + (A < 0) * 1000].push_back(abs(B) + (B > 0) * 1000);
        rv[abs(B) + (B < 0) * 1000].push_back(abs(A) + (A > 0) * 1000);

        std::stack<int> s;
        std::stack<int> st;

        for (int i = N; i >= 1; i--)
        {
            s.push(i);
            s.push(i + 1000);
        }

        bool visited[2020];
        bool visited2[2020];
        std::fill_n(visited, 2020, false);
        std::fill_n(visited2, 2020, false);

        while (!s.empty())
        {
            int pos = s.top();
            s.pop();
            if (visited[pos])
            {
                if (!visited2[pos])
                {
                    st.push(pos);
                    visited2[pos] = true;
                }
                continue;
            }
            visited[pos] = true;
            s.push(pos);
            for (auto it = v[pos].begin(); it != v[pos].end(); it++)
            {
                s.push(*it);
            }
        }
        std::set<int> set;

        bool isValid = true;

        std::fill_n(visited, 2020, false);
        while (!st.empty())
        {
            s.push(st.top());
            st.pop();
            while (!s.empty())
            {
                int pos = s.top();
                s.pop();
                if (visited[pos])
                    continue;
                visited[pos] = true;
                if (pos > 1000)
                {
                    if (set.find(pos - 1000) != set.end())
                    {
                        isValid = false;
                    }
                }
                set.insert(pos);
                for (auto it = rv[pos].begin(); it != rv[pos].end(); it++)
                {
                    s.push(*it);
                }
            }
            set.clear();
        }

        std::cout << ((isValid && set.find(1001) == set.end()) ? "yes\n" : "no\n");
    }
    return 0;
}