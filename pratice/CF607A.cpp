#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;

int n, a[MAXN], b[MAXN], f[MAXM << 2], vis[MAXM << 2];

int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]), vis[a[i]] = i;
        mx = max(mx, a[i]);
    }
    int ans = 0;
    for (int i = 0; i <= mx; i++)
    {
        if (vis[i])
            f[i] = (i - b[vis[i]] - 1 < 0) ? 1 : f[i - b[vis[i]] - 1] + 1;
        else
            f[i] = (i - 1 < 0) ? 0 : f[i - 1];
        ans = max(ans, f[i]);
    }
    printf("%d\n", n - ans);
    return 0;
}