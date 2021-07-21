#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void init()
{
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sta, 0, sizeof(sta));
    memset(insta, 0, sizeof(insta));
    memset(belong, 0, sizeof(belong));
    memset(Edge, 0, sizeof(Edge));
    cnt = top = dfncnt = sc = 0;
}

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

int trans(char *ss)
{
    int len = strlen(ss);
    int ret = (ss[len - 1] == 'h') ? n - 1 : 0;
    ss[len - 1] = '\0';
    ret += atoi(ss);
    return ret;
}

int opp(int u)
{
    return (u > n - 1) ? u - n + 1 : u + n - 1;
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

void trrans(int &u, char &c)
{
    if (u > n - 1)
        c = 'h', u -= n - 1;
    else
        c = 'w';
}

int main()
{
    while (1)
    {
        scanf("%d%d", &n, &m);
        if (n == 0 && m == 0)
            break;
        init();
        for (int i = 1; i <= m; i++)
        {
            char x[10], y[10];
            scanf("%s%s", x, y);
            int xx = trans(x);
            int yy = trans(y);
            addEdge(xx, opp(yy));
            addEdge(yy, opp(xx));
        }
        for (int i = 1; i <= 2 * (n - 1); i++)
            if (!dfn[i])
                tarjan(i);
        bool flag = true;
        for (int i = 1; i <= n - 1; i++)
        {
            if (belong[i] == belong[i + n - 1])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            printf("bad luck\n");
            continue;
        }
        for (int i = 1; i <= n - 1; i++)
        {
            int id;
            char ch;
            if (belong[i] < belong[i + n - 1])
                id = i + n - 1;
            else
                id = i;
            trrans(id, ch);
            printf("%d%c ", id, ch);
        }
        printf("\n");
    }
    return 0;
}