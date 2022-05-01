#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int n, m, f[MAXN][MAXN], ans, vis[MAXN];
vector<int> g[MAXN];

bool check(int u, int fa, int col)
{
    if (vis[u] && (vis[u] != col))
        return false;
    if (vis[u])
        return true;
    vis[u] = col;
    int nex = (col == 1) ? -1 : 1;
    for (auto v : g[u])
    {
        if (v == fa)
            continue;
        if (!check(v, u, nex))
            return false;
    }
    return true;
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            f[i][j] = 0x3f3f3f3f;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        f[u][v] = f[v][u] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && f[i][j] != 0x3f3f3f3f)
                ans = max(ans, f[i][j]);
    if (!check(1, 0, 1))
        printf("-1\n");
    else
        printf("%d\n", ans + 1);
    return 0;
}