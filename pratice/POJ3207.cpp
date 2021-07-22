#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, a[MAXN], b[MAXN];
int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, sc, dfncnt;

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void init()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sta, 0, sizeof(sta));
    memset(insta, 0, sizeof(insta));
    memset(belong, 0, sizeof(belong));
    memset(head, 0, sizeof(head));
    memset(Edge, 0, sizeof(Edge));
    cnt = dfncnt = top = sc = 0;
}

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

bool check(int a, int b, int c, int d)
{
    return (a < b && b < c && c < d);
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

bool solve(int m)
{
    for (int i = 1; i <= 2 * m; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
        if (belong[i] == belong[i + m])
            return false;
    return true;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            if (a[i] > b[i])
                swap(a[i], b[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (check(a[i], a[j], b[i], b[j]))
                {
                    addEdge(i, j + m);
                    addEdge(j + m, i);
                    addEdge(i + m, j);
                    addEdge(j, i + m);
                }
            }
        }
        if (solve(m))
            printf("panda is telling the truth...\n");
        else
            printf("the evil panda is lying again\n");
    }
    return 0;
}