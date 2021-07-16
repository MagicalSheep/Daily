#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 10;

ll tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN];
ll cnt, head[MAXN];

struct edge
{
    ll to, next;
} Edge[MAXN << 1];

void addEdge(ll u, ll v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs1(ll p)
{
    son[p] = -1;
    siz[p] = 1;
    for (ll e = head[p]; e; e = Edge[e].next)
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

void dfs2(ll p, ll t)
{
    top[p] = t;
    dfn[p] = ++tot;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (ll e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

struct node
{
    ll l, r, sum, s;
} tree[MAXN << 2];

void pushup(ll p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushdown(ll p)
{
    if (tree[p].s == -1)
        return;
    tree[p << 1].sum = tree[p].s * (tree[p << 1].r - tree[p << 1].l + 1);
    tree[p << 1 | 1].sum = tree[p].s * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
    tree[p << 1].s = tree[p << 1 | 1].s = tree[p].s;
    tree[p].s = -1;
}

void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].s = -1;
    if (s == t)
    {
        tree[p].sum = 0;
        return;
    }
    ll mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void update(ll p, ll s, ll t, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = v * (tree[p].r - tree[p].l + 1);
        tree[p].s = v;
        return;
    }
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        update(p << 1, s, t, v);
    if (t > mid)
        update(p << 1 | 1, s, t, v);
    pushup(p);
}

ll query(ll p, ll k)
{
    if (tree[p].l == tree[p].r)
        return tree[p].sum;
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        return query(p << 1, k);
    else
        return query(p << 1 | 1, k);
}

void emp(ll v)
{
    ll fv = top[v];
    while (fv != 1)
    {
        update(1, dfn[fv], dfn[v], 0), v = fa[fv];
        fv = top[v];
    }
    update(1, 1, dfn[v], 0);
}

ll n, q;

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        addEdge(a, b), addEdge(b, a);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        ll c, v;
        cin >> c >> v;
        if (c == 1)
            update(1, dfn[v], dfn[v] + siz[v] - 1, 1);
        else if (c == 2)
            emp(v);
        else
            cout << query(1, dfn[v]) << endl;
    }
    return 0;
}