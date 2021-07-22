#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

/** Persistent Segment Tree Begin **/
int tot, root[MAXN];

struct node
{
    int lson, rson, sum;
} tree[MAXN << 5];

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].lson = tree[rt].rson = tree[rt].sum = 0;
    if (s == t)
        return rt;
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    return rt;
}

// single point modification
int update(int p, int l, int r, int k, int v)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    tree[rt].sum += v;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (k <= mid)
        tree[rt].lson = update(tree[rt].lson, l, mid, k, v);
    else
        tree[rt].rson = update(tree[rt].rson, mid + 1, r, k, v);
    return rt;
}

// section sum query
int getsum(int p, int l, int r, int s, int t)
{
    if (l >= s && r <= t)
        return tree[p].sum;
    int mid = (l + r) >> 1;
    int ans = 0;
    if (s <= mid)
        ans += getsum(tree[p].lson, l, mid, s, t);
    if (t > mid)
        ans += getsum(tree[p].rson, mid + 1, r, s, t);
    return ans;
}

// section k-th small number query [root[l - 1], root[r]] <-> [p1, p2]
int query(int p1, int p2, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int sum = tree[tree[p2].lson].sum - tree[tree[p1].lson].sum;
    if (sum >= k)
        return query(tree[p1].lson, tree[p2].lson, l, mid, k);
    else
        return query(tree[p1].rson, tree[p2].rson, mid + 1, r, k - sum);
}
/** Persistent Segment Tree End **/

int main()
{
    int n = 5;
    root[0] = build(1, n);

    int a[6] = {0, 6, 2, 5, 3, 4};

    for (int i = 1; i <= n; i++)
        root[i] = update(root[i - 1], 1, n, a[i], 1);
    int ans = query(root[1], root[4], 1, n, 2);
}