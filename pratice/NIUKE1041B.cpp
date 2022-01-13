#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;

int n, a[MAXN], b[MAXN], f[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] > b[j])
                mx = max(mx, f[i - 1][j]);
            if (a[i] == b[j])
                f[i][j] = mx + 1;
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}