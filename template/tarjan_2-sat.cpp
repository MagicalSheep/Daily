#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

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

bool check(int data_num)
{
    for (int i = 1; i <= data_num; i++)
        if (belong[i] == belong[i + data_num])
            return false;
    return true;
}
/** Tarjan SCC End **/

int main()
{
    int n = 5;

    // add edges by limit cases

    // solve
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    if (check(n))
        printf("YES\n");
    else
        printf("NO\n");

    // print solution
    for (int i = 1; i <= n; i++)
    {
        if (belong[i] < belong[i + n])
            printf("%d is selected(true)\n", i);
        else
            printf("%d is selected(true)\n", i + n);
    }
}