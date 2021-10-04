#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e3 + 10;

ll t, n, H, a[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &H);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sort(a + 1, a + 1 + n, greater<ll>());
        ll ans = H / (a[1] + a[2]);
        ll rem = H - ans * (a[1] + a[2]);
        ans *= 2;
        if (rem)
        {
            if (rem <= a[1])
                ans += 1;
            else
                ans += 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}