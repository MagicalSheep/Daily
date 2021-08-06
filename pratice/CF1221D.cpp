#include <bits/stdc++.h>
#define INF 0xffffffffffffff
typedef long long ll;
using namespace std;
const int MAXN = 3e5 + 10;

int q, n, a[MAXN], b[MAXN];
ll f[MAXN][3];

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &a[i], &b[i]);
        f[0][0] = f[0][1] = f[0][2] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                f[i][j] = INF;
                for (int k = 0; k <= 2; k++)
                    if (a[i - 1] + k != a[i] + j)
                        f[i][j] = min(f[i][j], f[i - 1][k] + j * b[i]);
            }
        }
        ll ans = INF;
        for (int i = 0; i <= 2; i++)
            ans = min(ans, f[n][i]);
        printf("%I64d\n", ans);
    }
    return 0;
}