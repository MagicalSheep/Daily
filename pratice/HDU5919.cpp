#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int tot, a[MAXN], ans[MAXN], last[MAXN], root[MAXN];

struct node
{
    int lson, rson, val;
} tree[MAXN << 8];

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].lson = tree[rt].rson = tree[rt].val = 0;
    if (s == t)
        return rt;
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    return rt;
}

int update(int p, int k, int v, int l, int r)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    tree[rt].val += v;
    if (l == r)
        return rt;
    int mid = (l + r) >> 1;
    if (k <= mid)
        tree[rt].lson = update(tree[rt].lson, k, v, l, mid);
    else
        tree[rt].rson = update(tree[rt].rson, k, v, mid + 1, r);
    return rt;
}

int getsum(int p, int s, int t, int l, int r)
{
    if (l >= s && r <= t)
        return tree[p].val;
    int mid = (l + r) >> 1;
    int ans = 0;
    if (s <= mid)
        ans += getsum(tree[p].lson, s, t, l, mid);
    if (t > mid)
        ans += getsum(tree[p].rson, s, t, mid + 1, r);
    return ans;
}

int query(int p, int k, int l, int r)
{
    if (l == r)
        return l;
    int mid = (l + r) >> 1;
    int sum = tree[tree[p].lson].val;
    if (sum >= k)
        return query(tree[p].lson, k, l, mid);
    else
        return query(tree[p].rson, k - sum, mid + 1, r);
}

int T;

int main()
{
    scanf("%d", &T);
    for (int kk = 1; kk <= T; kk++)
    {
        tot = 0;
        memset(last, 0, sizeof(last));
        int n, m;
        scanf("%d%d", &n, &m);
        root[n + 1] = build(1, n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = n; i >= 1; i--)
        {
            if (last[a[i]])
            {
                root[i] = update(root[i + 1], last[a[i]], -1, 1, n);
                root[i] = update(root[i], i, 1, 1, n);
            }
            else
            {
                root[i] = update(root[i + 1], i, 1, 1, n);
            }
            last[a[i]] = i;
        }
        ans[0] = 0;
        for (int i = 1; i <= m; i++)
        {
            int l1, r1;
            scanf("%d%d", &l1, &r1);
            int l = min((l1 + ans[i - 1]) % n + 1, (r1 + ans[i - 1]) % n + 1);
            int r = max((l1 + ans[i - 1]) % n + 1, (r1 + ans[i - 1]) % n + 1);
            double len = getsum(root[l], l, r, 1, n);
            ans[i] = query(root[l], (len - 1) / 2 + 1, 1, n); // note: ceil()
        }
        printf("Case #%d:", kk);
        for (int i = 1; i <= m; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}