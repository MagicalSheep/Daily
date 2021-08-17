#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int T, f[MAXN], g[MAXN], aa;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(f, 0, sizeof(f));
        memset(g, 0x3f, sizeof(g));
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int a;
                scanf("%d", &a);
                if (i == 1 && j == 1)
                    aa = a;
                f[i] = max(f[i], a);
                g[j] = min(g[j], a);
            }
        }
        int ans = 0;
        if (k == 1)
        {
            ans = f[1];
        }
        else if (k & 1)
        {
            int mn = 0x3f3f3f3f;
            for (int i = 1; i <= n; i++)
                mn = min(mn, f[i]);
            ans = max(aa, mn);
        }
        else
        {
            int mx = 0;
            for (int i = 1; i <= m; i++)
                mx = max(mx, g[i]);
            ans = max(aa, mx);
        }
        printf("%d\n", ans);
    }
    return 0;
}