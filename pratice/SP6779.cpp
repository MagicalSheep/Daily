#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN];
ll cnt, head[MAXN];
ll N, Q, aa[MAXN];

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

struct node
{
    ll l, r, lm, rm, sum, ans, s, flag;
    node() { lm = rm = sum = ans = 0; }
} tree[MAXN << 2];

node merge(node x, node y)
{
    node ret;
    ret.l = x.l;
    ret.r = y.r;
    ret.sum = x.sum + y.sum;
    ret.lm = max(x.lm, x.sum + y.lm);
    ret.rm = max(y.rm, y.sum + x.rm);
    ret.ans = max(max(x.ans, y.ans), x.rm + y.lm);
    ret.s = ret.flag = 0;
    return ret;
}

void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    tree[p].s = 0;
    if (s == t)
    {
        tree[p].sum = aa[rnk[s]];
        tree[p].lm = tree[p].rm = tree[p].ans = max((ll)0, aa[rnk[s]]);
        tree[p].flag = 0;
        return;
    }
    ll mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

void pushdown(ll p)
{
    if (!tree[p].flag)
        return;
    tree[p << 1].sum = tree[p].s * (tree[p << 1].r - tree[p << 1].l + 1);
    tree[p << 1 | 1].sum = tree[p].s * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
    tree[p << 1].lm = tree[p << 1].rm = tree[p << 1].ans = max((ll)0, tree[p << 1].sum);
    tree[p << 1 | 1].lm = tree[p << 1 | 1].rm = tree[p << 1 | 1].ans = max((ll)0, tree[p << 1 | 1].sum);
    tree[p << 1].s = tree[p << 1 | 1].s = tree[p].s;
    tree[p << 1].flag = tree[p << 1 | 1].flag = 1; // note: fresh flag
    tree[p].s = tree[p].flag = 0;
}

void update(ll p, ll s, ll t, ll c)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = c * (tree[p].r - tree[p].l + 1);
        tree[p].lm = tree[p].rm = tree[p].ans = max((ll)0, tree[p].sum);
        tree[p].s = c;
        tree[p].flag = 1;
        return;
    }
    pushdown(p);
    ll mid = (tree[p].r + tree[p].l) >> 1;
    if (s <= mid)
        update(p << 1, s, t, c);
    if (t > mid)
        update(p << 1 | 1, s, t, c);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

node query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p];
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    node L, R;
    if (s <= mid)
        L = query(p << 1, s, t);
    if (t > mid)
        R = query(p << 1 | 1, s, t);
    return merge(L, R);
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
    ll fu = top[a], fv = top[b];
    node L, R;
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
            L = merge(query(1, dfn[fu], dfn[a]), L), a = fa[fu];
        else
            R = merge(query(1, dfn[fv], dfn[b]), R), b = fa[fv];
        fu = top[a];
        fv = top[b];
    }
    if (dep[a] > dep[b])
        L = merge(query(1, dfn[b], dfn[a]), L);
    else
        R = merge(query(1, dfn[a], dfn[b]), R);
    swap(L.lm, L.rm);
    return merge(L, R).ans;
}

int main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
        scanf("%lld", &aa[i]);
    for (int i = 1; i < N; i++)
    {
        ll u, v;
        scanf("%lld%lld", &u, &v);
        addEdge(u, v), addEdge(v, u);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, N);
    scanf("%lld", &Q);
    while (Q--)
    {
        ll o;
        scanf("%lld", &o);
        ll a, b, c;
        if (o == 1)
        {
            scanf("%lld%lld", &a, &b);
            cout << getans(a, b) << endl;
        }
        else
        {
            scanf("%lld%lld%lld", &a, &b, &c);
            modify(a, b, c);
        }
    }
    return 0;
}