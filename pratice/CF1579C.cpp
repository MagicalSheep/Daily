#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 5;
const int MAXM = 19 + 5;

int t, n, m, k, vis[MAXN][MAXM];
char ma[MAXN][MAXM];

void func(int x, int y)
{
    int ret = 0;
    int h = x - 1;
    for (int i = 1; i <= h && x - i >= 1 && y - i >= 1 && y + i <= m && ma[x - i][y - i] == '*' && ma[x - i][y + i] == '*'; i++)
        ++ret;
    if (ret >= k)
    {
        for (int i = 1; i <= h && x - i >= 1 && y - i >= 1 && y + i <= m && ma[x - i][y - i] == '*' && ma[x - i][y + i] == '*'; i++)
            vis[x - i][y - i] = 1, vis[x - i][y + i] = 1;
        vis[x][y] = 1;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
            scanf("%s", ma[i] + 1);
        memset(vis, 0, sizeof(vis));
        for (int i = k + 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ma[i][j] == '.')
                    continue;
                func(i, j);
            }
        }
        bool isok = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (ma[i][j] == '*' && vis[i][j] == 0)
                {
                    isok = false;
                    break;
                }
            }
            if (!isok)
                break;
        }
        if (!isok)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}