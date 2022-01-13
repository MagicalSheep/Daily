#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int n, l, k, d[MAXN], a[MAXN];
int f[MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &n, &l, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(f, 0x3f, sizeof(f));
    d[n + 1] = l;
    f[1][0] = 0;
    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= min(i - 1, k); j++)
            for (int p = 0; p <= j; p++)
                f[i][j] = min(f[i][j], f[i - p - 1][j - p] + a[i - p - 1] * (d[i] - d[i - p - 1]));
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; i++)
        ans = min(ans, f[n + 1][i]);
    printf("%d\n", ans);
    return 0;
}