#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int a[MAXN], n, q;

struct node
{
    ll l, r, flag, suflen, prelen, other;
} tree[MAXN << 2];

node merge(node x, node y)
{
    node ret;
    ret.l = x.l, ret.r = y.r;
    if (a[x.r] <= a[y.l])
    {
        if (x.flag && !y.flag)
        {
            ret.prelen = x.r - x.l + 1 + y.prelen;
            ret.suflen = y.suflen;
            ret.flag = 0;
            ret.other = y.other;
        }
        else if (!x.flag && y.flag)
        {
            ret.prelen = x.prelen;
            ret.suflen = y.r - y.l + 1 + x.suflen;
            ret.flag = 0;
            ret.other = x.other;
        }
        else if (x.flag && y.flag)
        {
            ret.prelen = ret.suflen = y.r - x.l + 1;
            ret.flag = 1;
            ret.other = 0;
        }
        else if (!x.flag && !y.flag)
        {
            ret.prelen = x.prelen;
            ret.suflen = y.suflen;
            ret.flag = 0;
            ll len = (y.l + y.prelen - 1) - (x.r - x.suflen + 1) + 1;
            ret.other = x.other + y.other + len * (len + 1) / 2;
        }
    }
    else
    {
        ret.flag = 0;
        ret.prelen = x.prelen;
        ret.suflen = y.suflen;
        if (x.flag && !y.flag)
            ret.other = y.other + y.prelen * (y.prelen + 1) / 2;
        else if (!x.flag && y.flag)
            ret.other = x.other + x.suflen * (x.suflen + 1) / 2;
        else if (x.flag && y.flag)
            ret.other = 0;
        else if (!x.flag && !y.flag)
            ret.other = x.other + y.other + x.suflen * (x.suflen + 1) / 2 + y.prelen * (y.prelen + 1) / 2;
    }
    return ret;
}

void build(int p, int s, int t)
{
    if (s == t)
    {
        tree[p].l = s, tree[p].r = t;
        tree[p].suflen = tree[p].prelen = tree[p].flag = 1;
        tree[p].other = 0;
        return;
    }
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

void update(int p, int k, int x)
{
    if (tree[p].l == tree[p].r)
    {
        a[k] = x;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        update(p << 1, k, x);
    else
        update(p << 1 | 1, k, x);
    tree[p] = merge(tree[p << 1], tree[p << 1 | 1]);
}

node query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p];
    int mid = (tree[p].l + tree[p].r) >> 1;
    node ret;
    // note: when using merge function to pushup, should use this "if style query"
    if (t <= mid)
        ret = query(p << 1, s, t);
    else if (s > mid)
        ret = query(p << 1 | 1, s, t);
    else
        ret = merge(query(p << 1, s, t), query(p << 1 | 1, s, t));
    return ret;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    int t, x, y;
    while (q--)
    {
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1)
        {
            update(1, x, y);
        }
        else
        {
            node ans = query(1, x, y);
            if (ans.flag)
                printf("%lld\n", (ans.r - ans.l + 1) * (ans.r - ans.l + 2) / 2);
            else
                printf("%lld\n", ans.suflen * (ans.suflen + 1) / 2 + ans.prelen * (ans.prelen + 1) / 2 + ans.other);
        }
    }
    return 0;
}