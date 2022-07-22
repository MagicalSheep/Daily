#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int t, n, q, a, b, c, fval;
int tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], mxw[MAXN];
vector<int> g[MAXN];

struct SegTree
{
    struct node
    {
        int flag[3], isok[3];
    } tree[MAXN << 2];

    void pushup(int p)
    {
        for (int i = 0; i < 3; i++)
            if (tree[p << 1].flag[i] == fval && tree[p << 1 | 1].flag[i] == fval)
                tree[p].flag[i] = fval;
        for (int i = 0; i < 3; i++)
            if (tree[p << 1].isok[i] == fval || tree[p << 1 | 1].isok[i] == fval)
                tree[p].isok[i] = fval;
    }

    void pushdown(int p)
    {
        for (int i = 0; i < 3; i++)
            if (tree[p].flag[i] == fval)
                tree[p << 1].flag[i] = tree[p << 1].isok[i] = tree[p << 1 | 1].flag[i] = tree[p << 1 | 1].isok[i] = fval;
    }

    void update(int p, int l, int r, int s, int t, int type)
    {
        if (l >= s && r <= t)
        {
            tree[p].flag[type] = tree[p].isok[type] = fval;
            return;
        }
        pushdown(p);
        int mid = (l + r) >> 1;
        if (s <= mid)
            update(p << 1, l, mid, s, t, type);
        if (t > mid)
            update(p << 1 | 1, mid + 1, r, s, t, type);
        pushup(p);
    }

    int query(int p, int l, int r)
    {
        if (tree[p].flag[0] == fval && tree[p].flag[1] == fval && tree[p].flag[2] == fval)
            return r - l + 1;
        if (l == r)
            return 0;
        pushdown(p);
        int mid = (l + r) >> 1, ret = 0;
        if (tree[p << 1].isok[0] == fval && tree[p << 1].isok[1] == fval && tree[p << 1].isok[2] == fval)
            ret += query(p << 1, l, mid);
        if (tree[p << 1 | 1].isok[0] == fval && tree[p << 1 | 1].isok[1] == fval && tree[p << 1 | 1].isok[2] == fval)
            ret += query(p << 1 | 1, mid + 1, r);
        return ret;
    }
};

void dfs1(int p)
{
    son[p] = -1;
    siz[p] = 1;
    for (auto v : g[p])
    {
        if (!dep[v])
        {
            dep[v] = dep[p] + 1;
            fa[v] = p;
            dfs1(v);
            siz[p] += siz[v];
            if (son[p] == -1 || siz[v] >= siz[son[p]])
                son[p] = v;
        }
    }
}

void dfs2(int p, int t)
{
    top[p] = t;
    mxw[p] = dfn[p] = ++tot;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    mxw[p] = max(mxw[p], mxw[son[p]]);
    for (auto v : g[p])
        if (v != son[p] && v != fa[p])
            dfs2(v, v), mxw[p] = max(mxw[p], mxw[v]);
}

SegTree tr;

void modify(int u, int v, int type)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        tr.update(1, 1, n, dfn[fu], dfn[u], type);
        u = fa[fu];
        fu = top[u];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    tr.update(1, 1, n, dfn[u], dfn[v], type);
}

void solve()
{
    int x;
    while (a--)
        scanf("%d", &x), modify(1, x, 0);
    while (b--)
        scanf("%d", &x), modify(1, x, 1);
    while (c--)
        scanf("%d", &x), tr.update(1, 1, n, dfn[x], mxw[x], 2);
    printf("%d\n", tr.query(1, 1, n));
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i < n; i++)
        {
            int r;
            scanf("%d", &r);
            g[r].emplace_back(i + 1);
        }
        dep[1] = 1;
        dfs1(1), dfs2(1, 1);
        while (q--)
        {
            ++fval;
            scanf("%d%d%d", &a, &b, &c);
            solve();
        }
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            fa[i] = dep[i] = siz[i] = son[i] = top[i] = dfn[i] = mxw[i] = 0;
            g[i].clear();
        }
    }
    return 0;
}