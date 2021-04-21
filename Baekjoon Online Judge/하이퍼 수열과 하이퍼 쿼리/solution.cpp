#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <unistd.h>
#define psi ps[im * n * o * p * q * r * s * t * u * v * w + in * o * p * q * r * s * t * u * v * w + io * p * q * r * s * t * u * v * w + ip * q * r * s * t * u * v * w + iq * r * s * t * u * v * w + ir * s * t * u * v * w + is * t * u * v * w + it * u * v * w + iu * v * w + iv * w + iw]
#define FOR(a, b, c, d, e, f, g, h, i, j, k)                          \
    for (ll im = a; im < m; ++im)                                     \
        for (ll in = b; in < n; ++in)                                 \
            for (ll io = c; io < o; ++io)                             \
                for (ll ip = d; ip < p; ++ip)                         \
                    for (ll iq = e; iq < q; ++iq)                     \
                        for (ll ir = f; ir < r; ++ir)                 \
                            for (ll is = g; is < s; ++is)             \
                                for (ll it = h; it < t; ++it)         \
                                    for (ll iu = i; iu < u; ++iu)     \
                                        for (ll iv = j; iv < v; ++iv) \
                                            for (ll iw = k; iw < w; ++iw)
#define DO(x)         \
    {                 \
        ll tmp = psi; \
        x--;          \
        tmp += psi;   \
        x++;          \
        psi = tmp;    \
    }

typedef long long ll;
namespace ios
{
    const signed IS = 1 << 18, OS = 1 << 18;
    char I[IS + 1], *J = I, O[OS], *K = O;

    inline void daer()
    {
        if (J >= I + IS - 64)
        {
            char *p = I;
            do
                *p++ = *J++;
            while (J != I + IS);
            p[read(0, p, I + IS - p)] = 0;
            J = I;
        }
    }
    template <int N = 18, typename T = ll>
    inline T getu()
    {
        daer();
        T x = 0;
        int k = 0;
        do
            x = x * 10 + *J - '0';
        while (*++J >= '0' && ++k < N);
        ++J;
        return x;
    }
    template <int N = 18, typename T = ll>
    inline T geti()
    {
        daer();
        bool e = *J == '-';
        J += e;
        return (e ? -1 : 1) * getu<N, T>();
    }
    inline void flush()
    {
        write(1, O, K - O);
        K = O;
    }

    template <int N = 16, typename T = ll>
    inline void putu(T n)
    {
        char s[(N + 7) / 8 * 8], *p = s;
        int k = 0;
        do
            *p++ = n % 10 + 48;
        while ((n /= 10) && ++k < N);
        do
            *K++ = *--p;
        while (p != s);
        *K++ = 10;
        if (K >= O + OS - 64)
            flush();
    }
    template <int N = 16, typename T = ll>
    inline void puti(T n)
    {
        if (n < 0)
            *K++ = '-', n = -n;
        putu<N, T>(n);
    }
    struct f
    {
        f() { I[read(0, I, IS)] = 0; }
        ~f() { flush(); }
    } flu;
}; // namespace ios
using namespace ios;

ll ps[1000000];
ll output;
bool back[11];

ll m, n, o, p, q, r, s, t, u, v, w, x, y, z;
ll em, en, eo, ep, eq, er, es, et, eu, ev, ew, ex;
ll find(ll a, ll b, ll c, ll d, ll e, ll f, ll g, ll h, ll i, ll j, ll k)
{
    if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0 || f < 0 || g < 0 || h < 0 || i < 0 || i < 0 || j < 0 || k < 0)
        return 0;
    return ps[a * n * o * p * q * r * s * t * u * v * w + b * o * p * q * r * s * t * u * v * w +
              c * p * q * r * s * t * u * v * w + d * q * r * s * t * u * v * w +
              e * r * s * t * u * v * w + f * s * t * u * v * w + g * t * u * v * w +
              h * u * v * w + i * v * w + j * w + k];
}
ll starts[11], ends[11];
void prefixSum(ll prot, ll st)
{
    ll XY = find(ends[0], ends[1], ends[2], ends[3], ends[4], ends[5], ends[6], ends[7], ends[8], ends[9], ends[10]);

    if (!XY)
        return;

    if (prot & 1)
        output += XY;
    else
        output -= XY;
    for (ll i = st; i < 11; i++)
    if (!back[i])
    {
        back[i] = true;
        ll temp = ends[i];
        ends[i] = starts[i] - 1;
        prefixSum(prot - 1, i + 1);
        back[i] = false;
        ends[i] = temp;
    }
}
int main(void)
{
    m = geti<>();
    n = geti<>();
    o = geti<>();
    p = geti<>();
    q = geti<>();
    r = geti<>();
    s = geti<>();
    t = geti<>();
    u = geti<>();
    v = geti<>();
    w = geti<>();

    FOR(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    {
        x = geti<>();
        psi = x;
    }
    FOR(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    DO(im)
    FOR(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    DO(in)
    FOR(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0)
    DO(io)
    FOR(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0)
    DO(ip)
    FOR(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0)
    DO(iq)
    FOR(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0)
    DO(ir)
    FOR(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0)
    DO(is)
    FOR(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0)
    DO(it)
    FOR(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0)
    DO(iu)
    FOR(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0)
    DO(iv)
    FOR(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1)
    DO(iw)

    z = geti<>();

    for (ll x = 0; x < z; ++x)
    {
        std::fill_n(back, 11, false);
        for (ll y = 0; y < 11; y++)
            starts[y] = geti<>() - 1;
        for (ll y = 0; y < 11; y++)
            ends[y] = geti<>() - 1;
        output = 0;
        prefixSum(11, 0);
        puti<19>(output);
    }

    return 0;
}
/*
 * 가나다라         eav
 * 가나다           eav
 * 
 */