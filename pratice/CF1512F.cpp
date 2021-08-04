#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, c, a[MAXN], b[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ll ans = 0x3f3f3f3f, money = 0;
        scanf("%lld%lld", &n, &c);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i < n; i++)
            scanf("%lld", &b[i]);
        ll days = 0, x = 1;
        while (1)
        {
            ans = min(ans, days + (ll)ceil(1.0 * (c - money) / a[x]));
            if (x == n)
                break;
            ll d = ceil(1.0 * (b[x] - money) / a[x]);
            days += d + 1;
            money = money + a[x] * d - b[x];
            ++x;
        }
        printf("%lld\n", ans);
    }
    return 0;
}