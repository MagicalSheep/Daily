#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

ll cnt, head[MAXN];
ll tot,
    fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN];
ll a[MAXN];

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

struct node
{
    ll l, r, sum, add;
} tree[MAXN << 2];

void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].add = 0;
    if (s == t)
    {
        tree[p].sum = a[rnk[s]];
        return;
    }
    ll mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushdown(ll p)
{
    tree[p << 1].sum += tree[p].add * (tree[p << 1].r - tree[p << 1].l + 1);
    tree[p << 1 | 1].sum += tree[p].add * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
    tree[p << 1].add += tree[p].add;
    tree[p << 1 | 1].add += tree[p].add;
    tree[p].add = 0;
}

void update(ll p, ll s, ll t, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum += v * (tree[p].r - tree[p].l + 1);
        tree[p].add += v;
        return;
    }
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        update(p << 1, s, t, v);
    if (t > mid)
        update(p << 1 | 1, s, t, v);
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    pushdown(p);
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
            if (son[p] == -1 || siz[Edge[e].to] >= siz[son[p]])
                son[p] = Edge[e].to;
        }
    }
}

void dfs2(ll p, ll t)
{
    top[p] = t;
    dfn[p] = ++tot;
    rnk[tot] = p;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (ll e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

ll getans(ll u, ll v)
{
    ll fu = top[u], fv = top[v];
    ll ret = 0;
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        ret += query(1, dfn[fu], dfn[u]);
        // do query for [dfn[fu], dfn[u]], and merge answer to ret
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    ret += query(1, dfn[u], dfn[v]);
    // do query for [dfn[u], dfn[v]], and merge answer to ret
    return ret;
}

ll N, M;

int main()
{
    scanf("%lld%lld", &N, &M);
    for (ll i = 1; i <= N; i++)
        scanf("%lld", &a[i]);
    for (ll i = 1; i < N; i++)
    {
        ll fr, to;
        scanf("%lld%lld", &fr, &to);
        addEdge(fr, to), addEdge(to, fr);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, N);
    while (M--)
    {
        ll o, x, a;
        scanf("%lld", &o);
        if (o == 1)
        {
            scanf("%lld%lld", &x, &a);
            update(1, dfn[x], dfn[x], a);
        }
        else if (o == 2)
        {
            scanf("%lld%lld", &x, &a);
            update(1, dfn[x], dfn[x] + siz[x] - 1, a);
        }
        else
        {
            scanf("%lld", &x);
            printf("%lld\n", getans(1, x));
        }
    }
    return 0;
}