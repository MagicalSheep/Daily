#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], dfn[MAXN], rnk[MAXN], top[MAXN];
ll cnt, head[MAXN];
ll aa[MAXN];

struct node
{
    ll l, r, sum, lc, rc, lazy;
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
    if (tree[p << 1].rc == tree[p << 1 | 1].lc)
        tree[p].sum--;
    tree[p].lc = tree[p << 1].lc;
    tree[p].rc = tree[p << 1 | 1].rc;
}

void pushdown(ll p)
{
    if (tree[p].lazy)
    {
        tree[p << 1].sum = tree[p << 1 | 1].sum = 1;
        tree[p << 1].lc = tree[p << 1].rc = tree[p << 1 | 1].lc = tree[p << 1 | 1].rc = tree[p].lazy;
        tree[p << 1].lazy = tree[p << 1 | 1].lazy = tree[p].lazy;
        tree[p].lazy = 0;
    }
}

void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].lazy = 0;
    if (s == t)
    {
        tree[p].lc = tree[p].rc = aa[rnk[s]];
        tree[p].sum = 1;
        return;
    }
    ll mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

void update(ll p, ll s, ll t, ll c)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = 1;
        tree[p].lc = tree[p].rc = tree[p].lazy = c;
        return;
    }
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        update(p << 1, s, t, c);
    if (t > mid)
        update(p << 1 | 1, s, t, c);
    pushup(p);
}

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll ans = 0;
    if (s > mid)
    {
        ans = query(p << 1 | 1, s, t);
    }
    else if (t <= mid)
    {
        ans = query(p << 1, s, t);
    }
    else
    {
        ans = query(p << 1, s, t) + query(p << 1 | 1, s, t);
        if (tree[p << 1].rc == tree[p << 1 | 1].lc) // note: query function also have to do this job
            ans--;
    }
    return ans;
}

ll getcolor(ll p, ll k)
{
    if (tree[p].l == tree[p].r)
        return tree[p].lc;
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        return getcolor(p << 1, k);
    else
        return getcolor(p << 1 | 1, k);
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
    tot++;
    dfn[p] = tot;
    rnk[tot] = p;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (ll e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

void modify(ll a, ll b, ll c)
{
    ll fu = top[a], fv = top[b];
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
            update(1, dfn[fu], dfn[a], c), a = fa[fu];
        else
            update(1, dfn[fv], dfn[b], c), b = fa[fv];
        fu = top[a];
        fv = top[b];
    }
    if (dep[a] >= dep[b])
        update(1, dfn[b], dfn[a], c);
    else
        update(1, dfn[a], dfn[b], c);
}

ll getans(ll a, ll b)
{
    ll ans = 0, fu = top[a], fv = top[b];
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
        {
            ans += query(1, dfn[fu], dfn[a]), a = fa[fu];
            if (getcolor(1, dfn[a]) == getcolor(1, dfn[fu]))
                ans--;
            fu = top[a];
        }
        else
        {
            ans += query(1, dfn[fv], dfn[b]), b = fa[fv];
            if (getcolor(1, dfn[b]) == getcolor(1, dfn[fv]))
                ans--;
            fv = top[b];
        }
    }
    if (dep[a] >= dep[b])
        ans += query(1, dfn[b], dfn[a]);
    else
        ans += query(1, dfn[a], dfn[b]);
    return ans;
}

ll n, m;

int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> aa[i];
    for (ll i = 1, x, y; i < n; i++)
    {
        cin >> x >> y;
        addEdge(x, y), addEdge(y, x);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        string o;
        ll a, b, c;
        cin >> o;
        if (o[0] == 'C')
        {
            cin >> a >> b >> c;
            modify(a, b, c);
        }
        else
        {
            cin >> a >> b;
            cout << getans(a, b) << endl;
        }
    }
    return 0;
}