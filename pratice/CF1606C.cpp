#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 10 + 5;

ll t, n, k, a[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll lft = k + 1, ans = 0;
        for (int i = 1; i < n; i++)
        {
            ll tmp = min(lft, (ll)pow(10, a[i + 1] - a[i]) - 1);
            lft -= tmp;
            ans += (ll)pow(10, a[i]) * tmp;
        }
        ans += (ll)pow(10, a[n]) * lft;
        printf("%lld\n", ans);
    }
    return 0;
}