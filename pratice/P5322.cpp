#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
const int MAXM = 2e4 + 10;

int s, n, m;
int a[MAXN][MAXN], g[MAXN][MAXM], f[MAXM];

int main()
{
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[j][i]);
    for (int i = 1; i <= n; i++)
        sort(a[i] + 1, a[i] + 1 + s);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++)
            g[i][j] = a[i][j] * 2 + 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= s && g[i][k] <= j; k++)
                f[j] = max(f[j], f[j - g[i][k]] + k * i);
    int ans = 0;
    for (int j = 0; j <= m; j++)
        ans = max(ans, f[j]);
    printf("%d\n", ans);
    return 0;
}