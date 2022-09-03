#include <bits/stdc++.h>
using namespace std;

int t, n, k, r, c;

void solve()
{
    bool mark[505][505] = {false};
    int upb = r - 1, lob = n - r;
    int cnt = 0;
    for (int cc = c; cnt < 2 * n; cc += k, cnt++)
    {
        if (cc >= 1 && cc <= n)
            mark[r][cc] = true;
        for (int i = 1; i <= upb; i++)
        {
            int x = r - i, y = cc - i;
            if (x < 1 || y < 1 || x > n || y > n)
                continue;
            mark[x][y] = true;
        }
        for (int i = 1; i <= lob; i++)
        {
            int x = r + i, y = cc + i;
            if (x < 1 || y < 1 || x > n || y > n)
                continue;
            mark[x][y] = true;
        }
    }
    cnt = 0;
    for (int cc = c - k; cnt < 2 * n; cc -= k, cnt++)
    {
        if (cc >= 1 && cc <= n)
            mark[r][cc] = true;
        for (int i = 1; i <= upb; i++)
        {
            int x = r - i, y = cc - i;
            if (x < 1 || y < 1 || x > n || y > n)
                continue;
            mark[x][y] = true;
        }
        for (int i = 1; i <= lob; i++)
        {
            int x = r + i, y = cc + i;
            if (x < 1 || y < 1 || x > n || y > n)
                continue;
            mark[x][y] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            putchar(mark[i][j] ? 'X' : '.');
        printf("\n");
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &n, &k, &r, &c);
        solve();
    }
    return 0;
}