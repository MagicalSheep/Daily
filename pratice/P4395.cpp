#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

int N, f[MAXN][20 + 5];
int cnt, head[MAXN];

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

void dfs(int u, int p)
{
    for (int j = 1; j <= 20; j++)
        f[u][j] = j;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (v == p)
            continue;
        dfs(v, u);
        for (int j = 1; j <= 20; j++)
        {
            int mn = 0x3f3f3f3f;
            for (int k = 1; k <= 20; k++)
            {
                if (j == k)
                    continue;
                mn = min(mn, f[v][k]);
            }
            f[u][j] += mn;
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v), addEdge(v, u);
    }
    dfs(1, 1);
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 20; i++)
        ans = min(ans, f[1][i]);
    printf("%d\n", ans);
}