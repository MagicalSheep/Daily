#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;

int q, n, t[MAXN], f[MAXN * MAXN][MAXN];

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &t[i]);
        sort(t + 1, t + 1 + n);
        memset(f, 0x3f, sizeof(f));
        for (int i = 0; i <= 200 * n; i++)
            f[i][0] = 0;
        for (int i = 1; i <= 200 * n; i++)
            for (int j = 1; j <= i; j++)
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + abs(i - t[j]));
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= 200 * n; i++)
            ans = min(ans, f[i][n]);
        printf("%d\n", ans);
    }
    return 0;
}