#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n, m, r, c;
char mm[MAXN][MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &m, &r, &c);
        for (int i = 1; i <= n; i++)
            scanf("%s", mm[i] + 1);
        if (mm[r][c] == 'B')
        {
            printf("0\n");
            continue;
        }
        bool isok = false;
        for (int i = 1; i <= m; i++)
        {
            if (mm[r][i] == 'B')
            {
                isok = true;
                break;
            }
        }
        if (isok)
        {
            printf("1\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (mm[i][c] == 'B')
            {
                isok = true;
                break;
            }
        }
        if (isok)
        {
            printf("1\n");
            continue;
        }
        bool has_b = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (mm[i][j] == 'B')
                    has_b = true;
        if (has_b)
            printf("2\n");
        else
            printf("-1\n");
    }
    return 0;
}