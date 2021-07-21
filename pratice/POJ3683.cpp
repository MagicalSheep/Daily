#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1e4 + 10;

int D[MAXN], N, start[MAXN];
int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void init()
{
    memset(D, 0, sizeof(D));
    memset(start, 0, sizeof(start));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sta, 0, sizeof(sta));
    memset(insta, 0, sizeof(insta));
    memset(belong, 0, sizeof(belong));
    memset(head, 0, sizeof(head));
    memset(Edge, 0, sizeof(Edge));
    top = dfncnt = sc = cnt = 0;
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
    if (low[u] == dfn[u])
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

int trans(char *tt)
{
    int ret = 0;
    char *p = strtok(tt, ":");
    ret = atoi(p) * 60;
    p = strtok(NULL, ":");
    ret += atoi(p);
    return ret;
}

bool check(int i, int j)
{
    return !(start[i] + D[i] <= start[j] || start[j] + D[j] <= start[i]);
}

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        init();
        for (int i = 1; i <= N; i++)
        {
            char s[20], t[20];
            scanf("%s%s%d", s, t, &D[i]);
            D[i + N] = D[i];
            start[i] = trans(s);
            start[i + N] = trans(t) - D[i];
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    continue;
                if (check(i, j))
                    addEdge(i, j + N);
                if (check(i, j + N))
                    addEdge(i, j);
                if (check(i + N, j))
                    addEdge(i + N, j + N);
                if (check(i + N, j + N))
                    addEdge(i + N, j);
            }
        }
        for (int i = 1; i <= 2 * N; i++)
            if (!dfn[i])
                tarjan(i);
        bool flag = true;
        for (int i = 1; i <= N; i++)
        {
            if (belong[i] == belong[i + N])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            printf("NO\n");
            break;
        }
        printf("YES\n");
        for (int i = 1; i <= N; i++)
        {
            if (belong[i] < belong[i + N])
                printf("%.2d:%.2d %.2d:%.2d\n", start[i] / 60, start[i] % 60, (start[i] + D[i]) / 60, (start[i] + D[i]) % 60);
            else
                printf("%.2d:%.2d %.2d:%.2d\n", start[i + N] / 60, start[i + N] % 60, (start[i + N] + D[i + N]) / 60, (start[i + N] + D[i + N]) % 60);
        }
    }
    return 0;
}