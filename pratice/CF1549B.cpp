#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

char str1[MAXN], str2[MAXN];
bool vis[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", str1);
        scanf("%s", str2);
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (str1[i] == '0' && str2[i] == '1')
            {
                vis[i] = 1;
                ans++;
                str2[i] = '0';
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str2[i] == '1' && str1[i - 1] == '1' && vis[i - 1] == 0)
            {
                ans++;
                vis[i - 1] = 1;
                str2[i] = '0';
                continue;
            }
            if (str2[i] == '1' && str1[i + 1] == '1' && vis[i + 1] == 0)
            {
                ans++;
                vis[i + 1] = 1;
                str2[i] = '0';
                continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}