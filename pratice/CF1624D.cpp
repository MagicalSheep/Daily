#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, k, vis[256];
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%s", &n, &k, s);
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[s[i]])
                vis[s[i]] = 0, ++cnt;
            else
                vis[s[i]] = 1;
        }
        int ans = (cnt / k) * 2;
        if (n - ans * k >= k)
            ++ans;
        printf("%d\n", ans);
    }
    return 0;
}