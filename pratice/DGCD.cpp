#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
typedef long long ll;
using namespace std;
const int MAXN = 5e4 + 10;

int tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN];
int cnt, head[MAXN];
int aa[MAXN], N, Q;
int ta[MAXN];

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
    int l, r, gc;
} tree[MAXN << 2];

void pushup(int p)
{
    tree[p].gc = __gcd(tree[p << 1].gc, tree[p << 1 | 1].gc);
}

void build(int p, int s, int t)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].gc = aa[s] - aa[s - 1];
        return;
    }
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void update(int p, int k, int v)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].gc += v;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        update(p << 1, k, v);
    else
        update(p << 1 | 1, k, v);
    pushup(p);
}

int query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].gc;
    int mid = (tree[p].l + tree[p].r) >> 1;
    int ans = 0;
    if (t <= mid)
        ans = query(p << 1, s, t);
    else if (s > mid)
        ans = query(p << 1 | 1, s, t);
    else
        ans = __gcd(query(p << 1, s, t), query(p << 1 | 1, s, t));
    return ans;
}

void add(int k, int v)
{
    for (; k <= N; k += lowbit(k))
        ta[k] += v;
}

int getnum(int k)
{
    int ret = 0;
    for (; k; k -= lowbit(k))
        ret += ta[k];
    return ret;
}

void modify(int u, int v, int d)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        add(dfn[fu], d), add(dfn[u] + 1, -d);
        update(1, dfn[fu], d);
        if (dfn[u] + 1 <= N)
            update(1, dfn[u] + 1, -d);
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    add(dfn[u], d), add(dfn[v] + 1, -d);
    update(1, dfn[u], d);
    if (dfn[v] + 1 <= N)
        update(1, dfn[v] + 1, -d);
}

int getans(int u, int v)
{
    int fu = top[u], fv = top[v], ret = 0;
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        ret = abs(__gcd(ret, getnum(dfn[fu])));
        if (dfn[fu] + 1 <= dfn[u])
            ret = abs(__gcd(ret, query(1, dfn[fu] + 1, dfn[u])));
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    ret = abs(__gcd(ret, getnum(dfn[u])));
    if (dfn[u] + 1 <= dfn[v])
        ret = abs(__gcd(ret, query(1, dfn[u] + 1, dfn[v])));
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a + 1, b + 1), addEdge(b + 1, a + 1);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= N; i++)
        scanf("%d", &aa[dfn[i]]);
    for (int i = 1; i <= N; i++)
        add(i, aa[i] - aa[i - 1]);
    build(1, 1, N);
    scanf("%d", &Q);
    while (Q--)
    {
        char o[10];
        int u, v, d;
        scanf("%s", o);
        if (o[0] == 'F')
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", getans(u + 1, v + 1));
        }
        else
        {
            scanf("%d%d%d", &u, &v, &d);
            modify(u + 1, v + 1, d);
        }
    }
    return 0;
}