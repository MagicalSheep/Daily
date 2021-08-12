#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int q, n, k, f[MAXN], g[MAXN], a[MAXN];

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        memset(f, 0x3f, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= k; i++)
            scanf("%d", &f[a[i]]), g[a[i]] = f[a[i]];
        for (int i = 1; i <= n; i++)
            f[i] = min(f[i], f[i - 1] + 1);
        for (int i = n; i >= 1; i--)
            g[i] = min(g[i], g[i + 1] + 1);
        for (int i = 1; i <= n; i++)
            printf("%d ", min(f[i], g[i]));
        printf("\n");
    }
    return 0;
}