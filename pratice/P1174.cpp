#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;

int n, m, k, val[MAXN][MAXN];
char flag[MAXN][MAXN];
int f[MAXN][MAXN][2], g[MAXN][MAXN][2];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &val[i][j]);
            getchar();
            flag[i][j] = getchar();
            getchar();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1, w = n; j <= k && w > 0; j++, w--)
        {
            if (flag[w][i] == 'N')
                g[i][j][1] = g[i][j][0] = g[i][j - 1][0] + val[w][i];
            else
                g[i][--j][0] += val[w][i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int x = 0; x <= min(n, j); x++)
            {
                f[i][j][0] = max(f[i][j][0], f[i - 1][j - x][0] + g[i][x][0]);
                if (x)
                    f[i][j][1] = max(f[i][j][1], f[i - 1][j - x][0] + g[i][x][1]);
                if (j - x)
                    f[i][j][1] = max(f[i][j][1], f[i - 1][j - x][1] + g[i][x][0]);
            }
        }
    }
    printf("%d\n", f[m][k][1]);
    return 0;
}