#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3;

int vis[MAXN];
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        char str[MAXN];
        scanf("%s", str);
        int len = strlen(str);
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (vis[(int)str[i]] >= 2)
                continue;
            ans++;
            vis[(int)str[i]]++;
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}