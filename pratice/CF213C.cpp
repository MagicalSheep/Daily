#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;

int n, a[MAXN][MAXN], f[MAXN << 1][MAXN][MAXN];

int main()
{
    memset(f, -0x3f, sizeof(f));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    f[1][1][1] = a[1][1];
    for (int i = 2; i <= 2 * n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                int val = 0;
                if (j == k)
                    val = a[j][i - j + 1];
                else
                    val = a[j][i - j + 1] + a[k][i - k + 1];
                f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + val);
                f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + val);
                f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + val);
                f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1] + val);
            }
        }
    }
    printf("%d\n", f[2 * n - 1][n][n]);
    return 0;
}