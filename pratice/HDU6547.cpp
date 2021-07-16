#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll cnt, head[MAXN];
ll tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN];

struct node
{
    ll l, r, sum;
} tree[MAXN << 2];

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

void pushup(ll p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}
void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].sum = 0;
    if (s == t)
        return;
    ll mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void set_value(ll p, ll k, ll v)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum = v;
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        set_value(p << 1, k, v);
    else
        set_value(p << 1 | 1, k, v);
    pushup(p);
}

void update(ll p, ll s, ll t)
{
    if (tree[p].r - tree[p].l + 1 == tree[p].sum)
        return;
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum = (ll)sqrt(tree[p].sum);
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        update(p << 1, s, t);
    if (t > mid)
        update(p << 1 | 1, s, t);
    pushup(p);
}

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll ans = 0;
    if (s <= mid)
        ans += query(p << 1, s, t);
    if (t > mid)
        ans += query(p << 1 | 1, s, t);
    return ans;
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
            if (son[p] == -1 || siz[Edge[e].to] > siz[son[p]])
                son[p] = Edge[e].to;
        }
    }
}

void dfs2(ll p, ll t)
{
    top[p] = t;
    tot++;
    dfn[p] = tot;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (ll e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

void modify(ll u, ll v)
{
    ll fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] > dep[fv]) // note: dep[fu] compare with dep[fv], instead of dep[u] and dep[v]
            update(1, dfn[fu], dfn[u]), u = fa[fu];
        else
            update(1, dfn[fv], dfn[v]), v = fa[fv];
        fu = top[u];
        fv = top[v];
    }
    if (dfn[u] > dfn[v])
        update(1, dfn[v], dfn[u]);
    else
        update(1, dfn[u], dfn[v]);
}

ll getans(ll u, ll v)
{
    ll ans = 0, fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] > dep[fv]) // note: dep[fu] compare with dep[fv], instead of dep[u] and dep[v]
            ans += query(1, dfn[fu], dfn[u]), u = fa[fu];
        else
            ans += query(1, dfn[fv], dfn[v]), v = fa[fv];
        fu = top[u];
        fv = top[v];
    }
    if (dfn[u] > dfn[v])
        ans += query(1, dfn[v], dfn[u]);
    else
        ans += query(1, dfn[u], dfn[v]);
    return ans;
}

ll n, q, a[MAXN];

int main()
{
    scanf("%lld%lld", &n, &q);
    build(1, 1, n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        addEdge(u, v), addEdge(v, u);
    }
    dep[1] = 1; // note: initialize the root depth
    dfs1(1), dfs2(1, 1);
    for (ll i = 1; i <= n; i++)
        set_value(1, dfn[i], a[i]);
    while (q--)
    {
        ll op, u, v;
        scanf("%lld%lld%lld", &op, &u, &v);
        if (op == 0)
            modify(u, v);
        else
            printf("%lld\n", getans(u, v));
    }
    return 0;
}
