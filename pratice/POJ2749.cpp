#include <algorithm>
#include <cstdio>
#include <math.h>
#include <string.h>
using namespace std;
const int MAXN = 1e3 + 10;

int N, A, B, dis1[MAXN], dis2[MAXN], ds;
int cnt, head[MAXN], cphead[MAXN], curcnt;
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

struct edge
{
    int to, next;
} Edge[MAXN * MAXN];

void init()
{
    memset(dis1, 0, sizeof(dis1));
    memset(dis2, 0, sizeof(dis2));
    memset(dfn, 0, sizeof(dfn));
    memset(insta, 0, sizeof(insta));
    memset(head, 0, sizeof(head));
    ds = cnt = top = dfncnt = sc = 0;
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

void add(int mid)
{
    for (int i = 1; i <= N; i++)
    {
        if (dis1[i] > mid)
            addEdge(i, i + N);
        if (dis2[i] > mid)
            addEdge(i + N, i);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            if (dis1[i] + dis1[j] > mid)
            {
                addEdge(i, j + N);
                addEdge(j, i + N);
            }
            if (dis2[i] + dis2[j] > mid)
            {
                addEdge(j + N, i);
                addEdge(i + N, j);
            }
            if (dis1[i] + ds + dis2[j] > mid)
            {
                addEdge(i, j);
                addEdge(j + N, i + N);
            }
            if (dis1[j] + ds + dis2[i] > mid)
            {
                addEdge(j, i);
                addEdge(i + N, j + N);
            }
        }
    }
}

bool solve()
{
    for (int i = 1; i <= 2 * N; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= N; i++)
        if (belong[i] == belong[i + N])
            return false;
    return true;
}

void clean()
{
    memset(dfn, 0, sizeof(dfn));
    memset(insta, 0, sizeof(insta));
    memcpy(head, cphead, sizeof(head));
    cnt = curcnt;
    top = sc = dfncnt = 0;
}

void backup()
{
    curcnt = cnt;
    memcpy(cphead, head, sizeof(head));
}

int main()
{
    while (scanf("%d%d%d", &N, &A, &B) != EOF)
    {
        init();
        int sx1, sy1, sx2, sy2;
        scanf("%d%d%d%d", &sx1, &sy1, &sx2, &sy2);
        ds = abs(sx1 - sx2) + abs(sy1 - sy2);
        for (int i = 1; i <= N; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            dis1[i] = abs(x - sx1) + abs(y - sy1);
            dis2[i] = abs(x - sx2) + abs(y - sy2);
        }
        while (A--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            addEdge(i, j + N);
            addEdge(j + N, i);
            addEdge(j, i + N);
            addEdge(i + N, j);
        }
        while (B--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            addEdge(i, j);
            addEdge(j, i);
            addEdge(i + N, j + N);
            addEdge(j + N, i + N);
        }
        backup();
        int l = 1, r = 0x3f3f3f3f, ans = -0x3f3f3f3f;
        bool isans = false;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            add(mid);
            if (solve())
            {
                ans = mid;
                isans = true;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            clean();
        }
        if (isans)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}