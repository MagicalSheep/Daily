#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

/** Sparse Table Begin **/
namespace ST
{
    const ll maxlog = 20;
    ll f[MAXN][maxlog + 5], logn[MAXN];

    // begin at index 1
    void init(ll *a, ll len)
    {
        for (ll i = 1; i <= len; i++)
            f[i][0] = a[i];
        logn[0] = -1;
        for (ll i = 1; i < MAXN; i++)
            logn[i] = logn[i >> 1] + 1;
        for (ll j = 1; j <= maxlog; j++)
            for (ll i = 1; i + (1 << j) - 1 <= len; i++)
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }

    // begin at index 1
    ll query(ll l, ll r)
    {
        ll j = logn[r - l + 1];
        return max(f[l][j], f[r - (1 << j) + 1][j]);
    }
}
/** Sparse Table End **/

ll n, w, fi[MAXN];

int main()
{
    scanf("%lld%lld", &n, &w);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &fi[i]);
    ST::init(fi, n);
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= n;)
        {
            ll ri = min(n, j + i - 1);
            sum += (ST::query(j, ri) + 1);
            j = ri + 1;
        }
        --sum;
        if (sum <= w)
        {
            ans = i;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}