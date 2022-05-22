#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

/** Graph Data Structure Begin **/
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
/** Graph Data Structure End **/

/** Tarjan SCC Begin **/
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfncnt;
    sta[++top] = u;
    insta[u] = 1;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (insta[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++sc;
        while (1)
        {
            int v = sta[top--];
            insta[v] = 0;
            belong[v] = sc;
            if (u == v)
                break;
        }
    }
}
/** Tarjan SCC End **/

int t, n, m, ind[MAXN];

void init()
{
    cnt = top = dfncnt = sc = 0;
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(sta, 0, sizeof(sta));
    memset(insta, 0, sizeof(insta));
    memset(ind, 0, sizeof(ind));
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j; j = Edge[j].next)
        {
            int v = Edge[j].to;
            if (belong[i] == belong[v])
                continue;
            ++ind[belong[v]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= sc; i++)
        if (ind[i] == 0)
            ++ans;
    printf("%d\n", ans - 1);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        solve();
    }
    return 0;
}