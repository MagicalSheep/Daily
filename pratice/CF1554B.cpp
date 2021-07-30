#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int t, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        ll ans = -0x3f3f3f3f;
        for (int i = n; i >= 2; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (1ll * i * j < ans)
                    break;
                ans = max(ans, 1ll * i * j - k * (a[i] | a[j]));
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}