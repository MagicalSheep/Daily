#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
const int MAXN = 2e3 + 5;

int n, k, f[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        f[1][i] = 1;
    for (int i = 2; i <= k; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; j * k <= n; k++)
                f[i][j] = (f[i][j] + f[i - 1][j * k]) % P;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + f[k][i]) % P;
    printf("%d\n", ans);
    return 0;
}