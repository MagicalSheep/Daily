#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 5e4 + 10;

int N, M;
int cnt, head[MAXN << 1], vis[MAXN << 1], ans[MAXN << 1], tot;

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

void dfs(int x)
{
    for (int e = head[x]; e; e = Edge[e].next)
    {
        if (!vis[e])
        {
            vis[e] = 1;
            dfs(Edge[e].to);
        }
    }
    ans[++tot] = x;
}

void init()
{
    memset(head, 0, sizeof(head));
    memset(Edge, 0, sizeof(Edge));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0, sizeof(ans));
    cnt = tot = 0;
}

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        init();
        while (M--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addEdge(x, y), addEdge(y, x);
        }
        dfs(1);
        for (int i = 1; i <= tot; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}