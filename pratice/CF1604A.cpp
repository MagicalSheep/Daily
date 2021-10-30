#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 100 + 5;

ll t, n, a[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] - i) <= ans)
                continue;
            ans += (a[i] - i - ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}