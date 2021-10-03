#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN], b[MAXN];
ll tr[MAXN];

void add(ll k, ll v)
{
    for (; k <= n; k += lowbit(k))
        tr[k] += v;
}

ll getsum(ll k)
{
    ll ret = 0;
    for (; k; k -= lowbit(k))
        ret += tr[k];
    return ret;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        memset(tr, 0, sizeof(tr));
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), b[i] = a[i];
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll x = getsum(a[i] - 1);
            ll y = getsum(n) - getsum(a[i]);
            ans += min(x, y);
            add(a[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}