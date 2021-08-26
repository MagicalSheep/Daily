#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e5 + 10;

int n, m, a[MAXN];

/** Persistent Segment Tree Begin **/
int tot, rt[MAXN];

struct node
{
    int lson, rson;
    ll sum, add;
} tree[MAXN << 5];

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].lson = tree[rt].rson = tree[rt].add = 0;
    if (s == t)
    {
        tree[rt].sum = 0;
        return rt;
    }
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    tree[rt].sum = tree[tree[rt].lson].sum + tree[tree[rt].rson].sum;
    return rt;
}

int update(int p, int l, int r, int s, int t, ll v)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    tree[rt].sum += v * (min(r, t) - max(l, s) + 1);
    if (l >= s && r <= t)
    {
        tree[rt].add += v;
        return rt;
    }
    int mid = (l + r) >> 1;
    if (s <= mid)
        tree[rt].lson = update(tree[rt].lson, l, mid, s, t, v);
    if (t > mid)
        tree[rt].rson = update(tree[rt].rson, mid + 1, r, s, t, v);
    return rt;
}

ll query(int p, int l, int r, int s, int t)
{
    if (l >= s && r <= t)
        return tree[p].sum;
    int mid = (l + r) >> 1;
    ll ans = tree[p].add * (min(r, t) - max(l, s) + 1);
    if (s <= mid)
        ans += query(tree[p].lson, l, mid, s, t);
    if (t > mid)
        ans += query(tree[p].rson, mid + 1, r, s, t);
    return ans;
}
/** Persistent Segment Tree End **/

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rt[0] = build(1, n);
    scanf("%d", &m);
    int l, r, w;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &l, &r, &w);
        rt[i] = update(rt[i - 1], 1, n, l, r, w);
    }
    int left, right, mid, ans;
    for (int i = 1; i <= n; i++)
    {
        if (query(rt[m], 1, n, i, i) < a[i])
        {
            printf("No\n");
            continue;
        }
        left = 1, right = m - 1, ans = m;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (query(rt[mid], 1, n, i, i) >= a[i])
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        printf("Yes %d\n", ans);
    }
    return 0;
}