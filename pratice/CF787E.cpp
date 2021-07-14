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

int query(int p, int s, int t)
{
    if (t < s)
        return 0;
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].val;
    int mid = (tree[p].l + tree[p].r) >> 1;
    int ans = 0;
    if (s <= mid)
        ans += query(tree[p].lson, s, t);
    if (t > mid)
        ans += query(tree[p].rson, s, t);
    return ans;
}

inline int get_diff_num(int l, int r)
{
    return query(rt[r], 1, r) - query(rt[r], 1, l - 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rt[0] = build(1, n);
    for (int i = 1; i <= n; i++)
    {
        if (last[a[i]])
        {
            rt[i] = update(rt[i - 1], last[a[i]], -1);
            rt[i] = update(rt[i], i, 1);
        }
        else
        {
            rt[i] = update(rt[i - 1], i, 1);
        }
        last[a[i]] = i;
    }
    for (int k = 1; k <= n; k++)
    {
        int l = 1, r = n, ans = 0;
        while (l <= n)
        {
            int pl = l, pr = n, rr = 0;
            while (pl <= pr)
            {
                int mid = (pl + pr) >> 1;
                if (get_diff_num(l, mid) > k)
                {
                    pr = mid - 1;
                }
                else
                {
                    rr = mid;
                    pl = mid + 1;
                }
            }
            ans++;
            l = rr + 1;
        }
        printf("%d ", ans);
    }
    return 0;
}