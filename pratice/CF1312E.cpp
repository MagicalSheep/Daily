#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int n, a[MAXN], f[MAXN][MAXN], dp[MAXN];

void prework()
{
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; len + i - 1 <= n; i++)
        {
            int j = len + i - 1;
            f[i][j] = -1;
            for (int k = i; k <= j; k++)
            {
                if (f[i][k] != -1 && f[i][k] == f[k + 1][j])
                {
                    f[i][j] = f[i][k] + 1;
                    break;
                }
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
        dp[i] = i;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= i; k++)
            if (f[k][i] != -1)
                dp[i] = min(dp[i], dp[k - 1] + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[i][i] = a[i];
    }
    prework();
    solve();
    printf("%d\n", dp[n]);
    return 0;
}