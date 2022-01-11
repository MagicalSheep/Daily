#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = 0, vis[MAXN] = {0};
        vis[0] = 1;
        for (int i = 1; i <= n; i++)
            if (!vis[abs(a[i])] || vis[abs(a[i])] == 1)
                ++ans, ++vis[abs(a[i])];
        printf("%d\n", ans);
    }
    return 0;
}