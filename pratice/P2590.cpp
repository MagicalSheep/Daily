#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 10;

int n, q, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN];
int tot, cnt, head[MAXN];

struct node
{
    int l, r, mx, sum;
} tree[MAXN << 2];

void pushup(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
}

void build(int p, int s, int t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].mx = tree[p].sum = 0;
    if (s == t)
        return;
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void update(int p, int k, int v)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum = v;
        tree[p].mx = v;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        update(p << 1, k, v);
    else
        update(p << 1 | 1, k, v);
    pushup(p);
}

int getsum(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    int mid = (tree[p].l + tree[p].r) >> 1;
    int ans = 0;
    if (s <= mid)
        ans += getsum(p << 1, s, t);
    if (t > mid)
        ans += getsum(p << 1 | 1, s, t);
    return ans;
}

int getmax(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].mx;
    int mid = (tree[p].l + tree[p].r) >> 1;
    int ans = -0x3f3f3f3f;
    if (s <= mid)
        ans = max(ans, getmax(p << 1, s, t));
    if (t > mid)
        ans = max(ans, getmax(p << 1 | 1, s, t));
    return ans;
}

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
    Edge[++cnt].to = u;
    Edge[cnt].next = head[v];
    head[v] = cnt;
}

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
            if (son[p] == -1 || siz[Edge[e].to] > siz[son[p]])
                son[p] = Edge[e].to;
        }
    }
}

void dfs2(int p, int t)
{
    top[p] = t;
    tot++;
    dfn[p] = tot;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (int e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

int qmax(int u, int v)
{
    int ret = -0x3f3f3f3f, fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
            ret = max(ret, getmax(1, dfn[fu], dfn[u])), u = fa[fu];
        else
            ret = max(ret, getmax(1, dfn[fv], dfn[v])), v = fa[fv];
        fu = top[u];
        fv = top[v];
    }
    if (dfn[u] < dfn[v])
        ret = max(ret, getmax(1, dfn[u], dfn[v]));
    else
        ret = max(ret, getmax(1, dfn[v], dfn[u]));
    return ret;
}

int qsum(int u, int v)
{
    int sum = 0, fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
            sum += getsum(1, dfn[fu], dfn[u]), u = fa[fu];
        else
            sum += getsum(1, dfn[fv], dfn[v]), v = fa[fv];
        fu = top[u];
        fv = top[v];
    }
    if (dfn[u] < dfn[v])
        sum += getsum(1, dfn[u], dfn[v]);
    else
        sum += getsum(1, dfn[v], dfn[u]);
    return sum;
}

int main()
{
    scanf("%d", &n);
    build(1, 1, n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= n; i++)
    {
        int w;
        scanf("%d", &w);
        update(1, dfn[i], w);
    }
    scanf("%d", &q);
    while (q--)
    {
        char o[20];
        int u, t;
        scanf("%s", o);
        scanf("%d%d", &u, &t);
        if (o[0] == 'C')
            update(1, dfn[u], t);
        else if (o[1] == 'M')
            printf("%d\n", qmax(u, t));
        else
            printf("%d\n", qsum(u, t));
    }
    return 0;
}