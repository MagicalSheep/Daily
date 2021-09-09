#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n;
char s[MAXN], ans[MAXN][MAXN], vis[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s + 1);
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    ans[i][j] = 'X';
                    continue;
                }
                if (i != 1 && i > j)
                {
                    char c = ans[j][i];
                    if (c == '+')
                        c = '-';
                    else if (c == '-')
                        c = '+';
                    if (c == '+')
                        vis[i] = 1;
                    ans[i][j] = c;
                    continue;
                }
                if (s[i] == '1' || s[j] == '1')
                {
                    ans[i][j] = '=';
                }
                else
                {
                    if (!flag)
                        ans[i][j] = '+', flag = true, vis[i] = 1;
                    else
                        ans[i][j] = '-';
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '2' && vis[i] == 0)
            {
                printf("NO\n");
                goto end;
            }
        }
        printf("YES\n");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                printf("%c", ans[i][j]);
            printf("\n");
        }
    end:
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}