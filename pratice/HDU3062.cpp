#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int cnt, head[MAXN];
int n, m;
int dfn[MAXN], low[MAXN], belong[MAXN], sc, dfncnt, top, sta[MAXN], insta[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN];

void init()
{
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(0));
    memset(belong, 0, sizeof(belong));
    memset(sta, 0, sizeof(sta));
    memset(insta, 0, sizeof(insta));
    memset(Edge, 0, sizeof(Edge));
    cnt = sc = dfncnt = top = 0;
}

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

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

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        init();
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            int A1, A2, C1, C2;
            scanf("%d%d%d%d", &A1, &A2, &C1, &C2);
            addEdge(2 * A1 + C1, 2 * A2 + (!C2));
            addEdge(2 * A2 + C2, 2 * A1 + (!C1));
        }
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i])
                tarjan(i);
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (belong[2 * i] == belong[2 * i + 1])
            {
                flag = false;
                break;
            }
        }
        printf((flag) ? "YES\n" : "NO\n");
    }
    return 0;
}