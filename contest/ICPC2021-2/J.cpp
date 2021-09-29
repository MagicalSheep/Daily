#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;

int n, m;
int h[MAXN][MAXN];
double w[MAXN][MAXN];
priority_queue<pair<int, pair<int, int>>> q;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &h[i][j]), w[i][j] = m, q.push(pair<int, pair<int, int>>(h[i][j], pair<int, int>(i, j)));
    while (q.size())
    {
        pair<int, pair<int, int>> p = q.top();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        double ww = w[x][y];
        int cnt = 0;
        if (x - 1 >= 1 && h[x][y] > h[x - 1][y])
            ++cnt;
        if (x + 1 <= n && h[x][y] > h[x + 1][y])
            ++cnt;
        if (y - 1 >= 1 && h[x][y] > h[x][y - 1])
            ++cnt;
        if (y + 1 <= n && h[x][y] > h[x][y + 1])
            ++cnt;
        double delta = ww / cnt;
        if (x - 1 >= 1 && h[x][y] > h[x - 1][y])
            w[x - 1][y] += delta;
        if (x + 1 <= n && h[x][y] > h[x + 1][y])
            w[x + 1][y] += delta;
        if (y - 1 >= 1 && h[x][y] > h[x][y - 1])
            w[x][y - 1] += delta;
        if (y + 1 <= n && h[x][y] > h[x][y + 1])
            w[x][y + 1] += delta;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (h[i][j] == 0)
                printf("%.6f ", w[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    return 0;
}