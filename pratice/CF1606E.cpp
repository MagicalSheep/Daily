#include <bits/stdc++.h>
typedef long long ll;
#define P 998244353
using namespace std;
const int MAXN = 500 + 5;

ll n, x, f[MAXN][MAXN];
ll fac[MAXN], inv[MAXN];

ll fpow_mod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}

ll getC(ll n, ll m) // C(n,m) = n!/((n-m)!*m!) % mod
{
    return fac[n] * inv[n - m] % P * inv[m] % P;
}

int main()
{
    scanf("%lld%lld", &n, &x);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1ll * fac[i - 1] * i % P;
        inv[i] = fpow_mod(fac[i], P - 2);
    }
    f[n][0] = 1;
    for (ll i = n; i > 1; i--)
    {
        for (ll j = 0; j <= x; j++)
        {
            if (!f[i][j])
                continue;
            ll nj = min(x, j + i - 1);
            for (ll k = i; k >= 0; k--)
            {
                f[k][nj] = (f[k][nj] + f[i][j] * getC(i, i - k) % P * fpow_mod(nj - j, i - k) % P) % P;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= x; i++)
        ans = (ans + f[0][i]) % P;
    printf("%lld\n", ans);
    return 0;
}