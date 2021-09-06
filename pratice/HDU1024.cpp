#include <bits/stdc++.h>
typedef long long ll;
#define INF 0x3f3f3f3f
using namespace std;

const int MAXN = 1e6 + 10;

int m, n;
ll a[MAXN], f[MAXN], g[MAXN];

int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        // ll ans = -INF;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = min(i, m); j >= 1; j--)
        //     {
        //         f[j] = max(f[j], g[j - 1]) + a[i];
        //         g[j] = max(g[j], f[j]);
        //         if (j == m)
        //             ans = max(ans, f[j]);
        //     }
        // }
        // printf("%lld\n", ans);
        ll temp;
        for (int j = 1; j <= m; j++)
        {
            temp = -1e9;
            for (int i = j; i <= n; i++)
            {
                f[i] = max(f[i - 1], g[i - 1]) + a[i];
                g[i - 1] = temp;
                temp = max(temp, f[i]);
            }
        }
        printf("%lld\n", temp);
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
    }
    return 0;
}