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

/** Tarjan Cut Vertices Begin **/
int dfn[MAXN], low[MAXN], dfncnt, iscut[MAXN];

void tarjan(int u, int rt)
{
    dfn[u] = low[u] = ++dfncnt;
    int child = 0;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v, rt);
            low[u] = min(low[u], low[v]);
            if (rt != u && low[v] >= dfn[u])
                iscut[u] = 1;
            if (rt == u)
                child++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if (rt == u && child >= 2)
        iscut[u] = 1;
}
/** Tarjan Cut Vertices End **/

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
}