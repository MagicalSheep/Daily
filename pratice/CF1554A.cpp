#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 10;

ll t, a[MAXN];

int main()
{
    scanf("%I64d", &t);
    a[0] = 1;
    while (t--)
    {
        ll ans = 0, n;
        scanf("%I64d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
            ans = max(ans, a[i] * a[i - 1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}