#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
using ll = long long;
using ld = long double;

using namespace __gnu_pbds;

auto gcdd = __gcd<ll>;
struct fraction
{
    ll a, b;
    fraction(ll _a, ll _b): a(_a), b(_b)
    {
        assert(a);
        if (b == 0) { a = 1; }
        // 분모 항상 양수
        if (a <  0) { a *= -1; b *= -1;}
        ll c = gcdd(a, b);
        a /= c; b /= c;
    }
    bool operator<(const fraction &f) const
    {
        __int128_t ia = a, ib = b, ja = f.a, jb = f.b;
        return ia * jb < ib * ja;
    }
};

struct my_order
{
    bool operator() (const fraction &a, const fraction &b) const
    {
        __int128_t ia = a.a, ib = a.b, ja = b.a, jb = b.b;
        return ia * jb < ja * ib;
    }
};

typedef tree<fraction, null_type, my_order, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set x_coord;

int main(int argc, char const *argv[])
{
    // cin.tie(NULL)->sync_with_stdio(false);
    int q; cin >> q;
    ll a, b, c;
    bool sign = false;
    bool strong_flag = false;
    string res = "";

    x_coord.insert(fraction(1LL, -9e18));
    x_coord.insert(fraction(1LL, 9e18));

    for (int x, i = 0; i < q; i++)
    {
        cin >> x;
        // ax + b 곱함
        if (x == 1)
        {
            cin >> a >> b;
            if (a == 0)
            {
                if (b == 0)
                    strong_flag = true;
                continue;
            }
            if (a < 0)  sign = !sign;  // 음수 기울기 -> 부호반전
            if(x_coord.find(fraction(-a, b)) == x_coord.end()){
                x_coord.insert(fraction(-a, b));
            } else {
                x_coord.erase(fraction(-a, b));
            }
        }
        else if (!strong_flag)
        {
            cin >> c;
            if (x_coord.find(fraction(1LL, c)) != x_coord.end())  // 교점 존재 -> 0
            {
                res += "0\n";
                continue;
            }
            int bigger_than_c = x_coord.size() - x_coord.order_of_key(fraction(1LL, c));
            // cout << x_coord.size() << " " << bigger_than_c << " &&\n";
            // fraction x = *x_coord.find_by_order(x_coord.order_of_key(fraction(1LL, c)));
            // cout <<x_coord.size() - bigger_than_c << " " << x.a << " " << x.b << "\n";
            
            if(((bigger_than_c%2) == 0)){
                res += "-\n";
            } else {
                res += "+\n";
            }
        }
        else
        {
            cin >> c;
            res += "0\n";
        }
    }
    cout << res;
    return 0;
}