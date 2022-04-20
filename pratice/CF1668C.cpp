#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e3 + 10;

ll n, a[MAXN];

ll solve(int x)
{
    ll last = 0, ret = 0;
    for (int i = x + 1; i <= n; i++)
    {
        if (a[i] > last)
        {
            last = a[i];
            ++ret;
            continue;
        }
        ll cnt = ceil(1.0 * (last + 1) / a[i]);
        ret += cnt;
        last = cnt * a[i];
    }
    last = 0;
    for (int i = x - 1; i >= 1; i--)
    {
        if (a[i] > last)
        {
            last = a[i];
            ++ret;
            continue;
        }
        ll cnt = ceil(1.0 * (last + 1) / a[i]);
        ret += cnt;
        last = cnt * a[i];
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    ll ans = 0x7fffffffffffffff;
    for (int i = 1; i <= n; i++)
        ans = min(ans, solve(i));
    printf("%lld\n", ans);
    return 0;
}