#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 5e5 + 10;

int a[MAXN];

/** Persistent Segment Tree Begin **/
int tot, root[MAXN << 1];

struct node
{
    int lson, rson, mn, pos;
} tree[MAXN << 6];

void pushup(int p)
{
    if (tree[tree[p].lson].mn < tree[tree[p].rson].mn)
        tree[p].mn = tree[tree[p].lson].mn, tree[p].pos = tree[tree[p].lson].pos;
    else
        tree[p].mn = tree[tree[p].rson].mn, tree[p].pos = tree[tree[p].rson].pos;
}

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].lson = tree[rt].rson = 0;
    if (s == t)
    {
        tree[rt].mn = INF;
        tree[rt].pos = s;
        return rt;
    }
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    pushup(rt);
    return rt;
}

// single point modification
int update(int p, int l, int r, int k, int v)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    if (l == r)
    {
        tree[rt].mn = v;
        tree[rt].pos = l;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
        tree[rt].lson = update(tree[rt].lson, l, mid, k, v);
    else
        tree[rt].rson = update(tree[rt].rson, mid + 1, r, k, v);
    pushup(rt);
    return rt;
}

// section sum query
pair<int, int> getsum(int p, int l, int r, int s, int t)
{
    if (l >= s && r <= t)
    {
        pair<int, int> pp;
        pp.second = tree[p].pos;
        pp.first = tree[p].mn;
        return pp;
    }
    int mid = (l + r) >> 1;
    if (t <= mid)
        return getsum(tree[p].lson, l, mid, s, t);
    else if (s > mid)
        return getsum(tree[p].rson, mid + 1, r, s, t);
    else
        return min(getsum(tree[p].lson, l, mid, s, t), getsum(tree[p].rson, mid + 1, r, s, t));
}
/** Persistent Segment Tree End **/

int n, q, last[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]])
        {
            root[i] = update(root[i - 1], 1, n, last[a[i]], INF);
            root[i] = update(root[i], 1, n, i, last[a[i]]);
        }
        else
        {
            root[i] = update(root[i - 1], 1, n, i, 0);
        }
        last[a[i]] = i;
    }
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        pair<int, int> ans = getsum(root[r], 1, n, l, r);
        if (ans.first < l)
            printf("%d\n", a[ans.second]);
        else
            printf("0\n");
    }
    return 0;
}