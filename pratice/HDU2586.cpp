#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e4 + 10;

int fa[MAXN];
int cnt, head[MAXN], qcnt, qhead[MAXN];
int vis[MAXN], dis[MAXN], ques[MAXN];
map<pair<int, int>, int> lca;

void init()
{
    memset(fa, 0, sizeof(fa));
    memset(head, 0, sizeof(head));
    memset(qhead, 0, sizeof(qhead));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(ques, 0, sizeof(ques));
    lca.clear();
    cnt = qcnt = 0;
}

struct edge
{
    int from, to, next, val;
} Edge[MAXN << 1], QEdge[MAXN << 1];

void addEdge(int u, int v, int k)
{
    Edge[++cnt].to = v;
    Edge[cnt].val = k;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void addQEdge(int u, int v)
{
    QEdge[++qcnt].to = v;
    QEdge[qcnt].from = u;
    QEdge[qcnt].next = qhead[u];
    qhead[u] = qcnt;
}

int find(int x)
{
    return fa[x] == x ? x : find(fa[x]);
}

void unionSet(int x, int y)
{
    fa[find(y)] = find(x); // note: unionSet will influence solving lca, let v's father equal u
}

void tarjan(int u)
{
    vis[u] = 1;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!vis[v])
        {
            dis[v] = dis[u] + Edge[e].val;
            tarjan(v);
            unionSet(u, v);
        }
    }
    for (int e = qhead[u]; e; e = QEdge[e].next)
    {
        int v = QEdge[e].to;
        if (vis[v])
            lca.insert(pair<pair<int, int>, int>(pair<int, int>(u, v), find(v)));
    }
}

int T;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i < n; i++)
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            addEdge(x, y, k), addEdge(y, x, k);
        }
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addQEdge(x, y);
            ques[i] = qcnt;
        }
        tarjan(1);
        for (int i = 1; i <= m; i++)
        {
            int u = QEdge[ques[i]].from;
            int v = QEdge[ques[i]].to;
            int lc = lca.at(pair<int, int>(u, v));
            int ans = dis[u] + dis[v] - 2 * dis[lc];
            printf("%d\n", ans);
        }
    }
    return 0;
}