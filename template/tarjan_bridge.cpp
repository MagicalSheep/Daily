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

/** Tarjan Bridge Begin **/
int dfn[MAXN], low[MAXN], dfncnt, isbridge[MAXN], bricnt, fa[MAXN];

void tarjan(int u, int p)
{
    fa[u] = p;
    dfn[u] = low[u] = ++dfncnt;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                isbridge[v] = 1;
                ++bricnt;
            }
        }
        else if (dfn[v] < dfn[u] && v != p)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
/** Tarjan Bridge End **/

int main()
{
    tarjan(1, 0);

    int n = 5;
    // print bridge
    for (int i = 1; i <= n; i++)
        if (isbridge[i])
            printf("%d -> %d", fa[i], i);
}