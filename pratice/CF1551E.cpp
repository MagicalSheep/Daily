#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;

int t, a[MAXN], f[MAXN][MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(f, 0, sizeof(f));
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                f[i][j] = max(f[i][j], f[i - 1][j]);
                if (a[i] == j + 1)
                    f[i][j + 1] = max(f[i][j + 1], f[i - 1][j] + 1);
                else
                    f[i][j + 1] = max(f[i][j + 1], f[i - 1][j]);
            }
        }
        int ans = -1;
        for (int j = n; j >= 0; j--)
        {
            if (f[n][j] >= k)
            {
                ans = n - j;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}