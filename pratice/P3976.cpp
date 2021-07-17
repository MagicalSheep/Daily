#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e4 + 10;

int tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN];
int cnt, head[MAXN];
int N, Q, aa[MAXN];

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
    rnk[tot] = p;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (int e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

struct node
{
    int l, r, mx, mn, lm, rm, add;
    node() { l = r = mx = mn = lm = rm = add = 0; }
} tree[MAXN << 2];

void pushup(int p)
{
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    tree[p].mn = min(tree[p << 1].mn, tree[p << 1 | 1].mn);
    tree[p].lm = max(max(tree[p << 1].lm, tree[p << 1 | 1].lm), tree[p << 1].mx - tree[p << 1 | 1].mn);
    tree[p].rm = max(max(tree[p << 1].rm, tree[p << 1 | 1].rm), tree[p << 1 | 1].mx - tree[p << 1].mn);
}

void pushdown(int p)
{
    if (!tree[p].add)
        return;
    tree[p << 1].mx += tree[p].add, tree[p << 1].mn += tree[p].add;
    tree[p << 1 | 1].mx += tree[p].add, tree[p << 1 | 1].mn += tree[p].add;
    tree[p << 1].add += tree[p].add;
    tree[p << 1 | 1].add += tree[p].add;
    tree[p].add = 0;
}

void build(int p, int s, int t)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].mx = tree[p].mn = aa[rnk[s]]; // note: leaf node lm and rm is 0
        return;
    }
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void update(int p, int s, int t, int v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].mx += v, tree[p].mn += v;
        tree[p].add += v;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        update(p << 1, s, t, v);
    if (t > mid)
        update(p << 1 | 1, s, t, v);
    pushup(p);
}

node merge(node a, node b)
{
    node ret;
    ret.l = a.l, ret.r = b.r;
    ret.mx = max(a.mx, b.mx);
    ret.mn = min(a.mn, b.mn);
    ret.lm = max(max(a.lm, b.lm), a.mx - b.mn);
    ret.rm = max(max(a.rm, b.rm), b.mx - a.mn);
    return ret;
}

node query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p];
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    node ans;
    if (s > mid)
        ans = query(p << 1 | 1, s, t);
    else if (t <= mid)
        ans = query(p << 1, s, t);
    else
        ans = merge(query(p << 1, s, t), query(p << 1 | 1, s, t));
    return ans;
}

void modify(int a, int b, int v)
{
    int fu = top[a], fv = top[b];
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(fu, fv), swap(a, b);
        update(1, dfn[fu], dfn[a], v), a = fa[fu];
        fu = top[a];
    }
    if (dep[a] >= dep[b])
        swap(a, b);
    update(1, dfn[a], dfn[b], v);
}

int getans(int a, int b)
{
    int fu = top[a], fv = top[b];
    node l, r;
    l.mn = r.mn = 0x3f3f3f3f;
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
            l = merge(query(1, dfn[fu], dfn[a]), l), a = fa[fu];
        else
            r = merge(query(1, dfn[fv], dfn[b]), r), b = fa[fv];
        fu = top[a];
        fv = top[b];
    }
    if (dep[a] >= dep[b])
        l = merge(query(1, dfn[b], dfn[a]), l);
    else
        r = merge(query(1, dfn[a], dfn[b]), r);
    swap(l.lm, l.rm);
    return merge(l, r).rm;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &aa[i]);
    for (int i = 1; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        addEdge(x, y), addEdge(y, x);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, N);
    scanf("%d", &Q);
    while (Q--)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        printf("%d\n", getans(a, b));
        modify(a, b, v);
    }
    return 0;
}