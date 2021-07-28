#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T, n, a[100 + 10][100 + 10], b[100 + 10][100 + 10];
int f[100 + 10][100 + 10][10000];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &b[i][j]);
        memset(f, -0x3f, sizeof(f));
        f[1][1][a[1][1]] = b[1][1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = a[i][j]; k <= 10000; k++)
                {
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - a[i][j]] + b[i][j]);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - a[i][j]] + b[i][j]);
                }
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= 10000; i++)
            ans = max(ans, i * (ll)f[n][n][i]);
        printf("%lld\n", ans);
    }
    return 0;
}