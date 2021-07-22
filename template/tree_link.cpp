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

/** Tree Link Begin **/
int tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN];

void dfs1(int p)
{
    son[p] = -1;
    siz[p] = 1;
    for (int e = head[p]; e; e = Edge[e].next)
    {
        if (!dep[Edge[e].to])
        {
            dep[Edge[e].to] = dep[p] + 1;
            fa[Edge[e].to] = p;
            dfs1(Edge[e].to);
            siz[p] += siz[Edge[e].to];
            if (son[p] == -1 || siz[Edge[e].to] >= siz[son[p]])
                son[p] = Edge[e].to;
        }
    }
}

void dfs2(int p, int t)
{
    top[p] = t;
    dfn[p] = ++tot;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (int e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

void modify(int u, int v, int c)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        // do sth for [dfn[fu], dfn[u]]
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    // do sth for [dfn[u], dfn[v]]
}

int getans(int u, int v)
{
    int fu = top[u], fv = top[v], ret = 0;
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        // do query for [dfn[fu], dfn[u]], and merge answer to ret
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    // do query for [dfn[u], dfn[v]], and merge answer to ret
    return ret;
}
/** Tree Link End **/

int main()
{
    dep[1] = 1; // important
    dfs1(1), dfs2(1, 1);

    modify(1, 3, 5);
    int ans = getans(1, 3);
}