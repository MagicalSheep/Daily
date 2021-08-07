#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, k, x[MAXN], f[MAXN][2];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        for (int i = 1; i <= n; i++)
            scanf("%*d");
        sort(x + 1, x + 1 + n);
        for (int i = 1, j = 1, cnt = 1; i <= n; i++)
        {
            while (x[j] + k < x[i])
                ++j, --cnt;
            f[i][0] = max(f[i - 1][0], cnt);
            f[i][1] = max(f[i - 1][1], f[j - 1][0] + cnt);
            ++cnt;
        }
        printf("%d\n", f[n][1]);
    }
    return 0;
}