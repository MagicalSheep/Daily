#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int tot, n, a[MAXN], last[MAXN], rt[MAXN << 1];

struct node
{
    int l, r, lson, rson, val;
} tree[MAXN << 7];

int build(int s, int t)
{
    int rt = tot++;
    tree[rt].l = s;
    tree[rt].r = t;
    tree[rt].val = 0;
    if (s == t)
        return rt;
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    return rt;
}

int update(int p, int k, int v)
{
    int rt = tot++;
    tree[rt] = tree[p];
    tree[rt].val += v;
    if (tree[rt].r == tree[rt].l)
        return rt;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (k <= mid)
        tree[rt].lson = update(tree[rt].lson, k, v);
    else
        tree[rt].rson = update(tree[rt].rson, k, v);
    return rt;
}

int query(int p, int k) // k-th small
{
    if (tree[p].l == tree[p].r)
        return tree[p].l;
    if (k <= tree[tree[p].lson].val)
        return query(tree[p].lson, k);
    else
        return query(tree[p].rson, k - tree[tree[p].lson].val);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rt[n + 1] = build(1, n + 1); // n + 1
    for (int i = n; i >= 1; i--)
    {
        if (last[a[i]])
        {
            rt[i] = update(rt[i + 1], last[a[i]], -1);
            rt[i] = update(rt[i], i, 1);
        }
        else
        {
            rt[i] = update(rt[i + 1], i, 1);
        }
        last[a[i]] = i;
    }
    for (int k = 1; k <= n; k++)
    {
        int l = 1, ans = 0;
        while (l <= n)
        {
            l = query(rt[l], k + 1);
            ans++;
        }
        printf("%d ", ans);
    }
    return 0;
}