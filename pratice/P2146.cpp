#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

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

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        ll len = tree[p].r - tree[p].l + 1;
        return len - tree[p].sum;
    }
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll ret = 0;
    if (s <= mid)
        ret += query(p << 1, s, t);
    if (t > mid)
        ret += query(p << 1 | 1, s, t);
    return ret;
}

void modify(ll x)
{
    ll fx = top[x];
    while (fx != 1)
    {
        update(1, dfn[fx], dfn[x], 1), x = fa[fx];
        fx = top[x];
    }
    update(1, 1, dfn[x], 1);
}

ll getans(ll x)
{
    ll ans = 0, fx = top[x];
    while (fx != 1)
    {
        ans += query(1, dfn[fx], dfn[x]), x = fa[fx];
        fx = top[x];
    }
    ans += query(1, 1, dfn[x]);
    return ans;
}

ll n, q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        addEdge(tmp + 1, i + 1), addEdge(i + 1, tmp + 1);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    string o;
    ll x;
    while (q--)
    {
        cin >> o >> x;
        if (o[0] == 'i')
        {
            cout << getans(x + 1) << endl;
            modify(x + 1);
        }
        else
        {
            cout << siz[x + 1] - query(1, dfn[x + 1], dfn[x + 1] + siz[x + 1] - 1) << endl;
            update(1, dfn[x + 1], dfn[x + 1] + siz[x + 1] - 1, 0); // note: learn how to modify all the children of a node
        }
    }
    return 0;
}