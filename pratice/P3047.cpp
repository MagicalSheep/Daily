#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, k, c[MAXN];
int cnt, head[MAXN];
int f[MAXN][20 + 5], g[MAXN][20 + 5];

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(int u, int p)
{
    f[u][0] = c[u];
    for (int e = head[u]; e; e = Edge[e].next)
        if (Edge[e].to != p)
            dfs1(Edge[e].to, u);
    for (int j = 1; j <= k; j++)
    {
        f[u][j] = c[u];
        for (int e = head[u]; e; e = Edge[e].next)
        {
            int v = Edge[e].to;
            if (v == p)
                continue;
            f[u][j] += f[v][j - 1];
        }
    }
}

void dfs2(int u, int p)
{
    g[u][0] = c[u];
    g[u][1] = g[p][0] + f[u][1];
    for (int j = 2; j <= k; j++)
        g[u][j] = g[p][j - 1] - f[u][j - 2] + f[u][j];
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (v == p)
            continue;
        dfs2(v, u);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v), addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    dfs1(1, 1);
    for (int i = 0; i <= k; i++)
        g[1][i] = f[1][i];
    for (int e = head[1]; e; e = Edge[e].next)
        dfs2(Edge[e].to, 1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", g[i][k]);
    return 0;
}