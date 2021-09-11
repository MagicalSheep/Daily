#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int n, a[MAXN], b[MAXN], f[MAXN][MAXN * MAXN], tot;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]), tot += b[i];
    memset(f, -0x3f, sizeof(f)); // note: some state cannot be achieved
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            for (int k = 10000; k >= a[i]; k--)
                f[j][k] = max(f[j][k], f[j - 1][k - a[i]] + b[i]);
    for (int i = 1; i <= n; i++)
    {
        double ans = 0;
        for (int j = 0; j <= 10000; j++)
            ans = max(ans, min(1.0 * j, (f[i][j] + tot) / 2.0));
        printf("%.10f\n", ans);
    }
    return 0;
}