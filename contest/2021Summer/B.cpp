#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;

int n, f[MAXN << 1], g[MAXN << 1];
int v[8] = {0, 1, 6, 28, 88, 198, 328, 648};
int w[8] = {0, 10 + 8, 60 + 18, 280 + 28, 880 + 58, 1980 + 128, 3280 + 198, 6480 + 388};
int w2[8] = {0, 10, 60, 280, 880, 1980, 3280, 6480};

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 7; i++)
        for (int j = n; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int m = n - i;
        for (int j = 1; j <= 7; j++)
            for (int k = v[j]; k <= m; k++)
                g[k] = max(g[k], g[k - v[j]] + w2[j]);
        ans = max(ans, f[i] + g[m]);
    }
    printf("%d\n", ans);
    return 0;
}