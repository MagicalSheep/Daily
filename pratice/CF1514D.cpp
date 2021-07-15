#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e5 + 10;

int tot, root[MAXN << 5];

struct node
{
    int l, r, lson, rson;
    ll sum;
} tree[MAXN << 5];

struct tt
{
    int idx, val, rnk;
} a[MAXN];

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].l = s; // note: don't forget initialize it
    tree[rt].r = t;
    tree[rt].lson = tree[rt].rson = tree[rt].sum = 0;
    if (s == t)
        return rt;
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    return rt;
}

int update(int p, int k)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    tree[rt].sum += 1;
    if (tree[rt].l == tree[rt].r)
        return rt;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (k <= mid)
        tree[rt].lson = update(tree[rt].lson, k);
    else
        tree[rt].rson = update(tree[rt].rson, k);
    return rt;
}

int query(int p1, int p2, int k)
{
    if (tree[p1].l == tree[p1].r)
        return tree[p2].sum - tree[p1].sum;
    int sum = tree[tree[p2].lson].sum - tree[tree[p1].lson].sum;
    if (sum > k) // note: strictly greater than k
        return query(tree[p1].lson, tree[p2].lson, k);
    else
        return query(tree[p1].rson, tree[p2].rson, k);
}

int n, q;

bool cmp1(const tt &a, const tt &b) { return a.val < b.val; }
bool cmp2(const tt &a, const tt &b) { return a.idx < b.idx; }

int main()
{
    cin >> n >> q;
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].idx = i;
    }
    sort(a + 1, a + 1 + n, cmp1);
    int rnk = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != 1 && a[i].val == a[i - 1].val)
            a[i].rnk = a[i - 1].rnk;
        else
            a[i].rnk = ++rnk;
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
        root[i] = update(root[i - 1], a[i].rnk);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int limit = (r - l + 1) >> 1;
        int x = query(root[l - 1], root[r], limit);
        cout << max(1, 2 * x - (r - l + 1)) << endl;
    }
    return 0;
}