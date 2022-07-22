#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;
const ll INF = 1e18;

int t, n, m, a[MAXN];

struct SegTree
{
    struct node
    {
        int l, r;
        ll mx1, mx2, mn1, mn2, res1, res2, res1_mx, res1_mn;

        node operator+(node &x)
        {
            node ret;
            ret.mx1 = ret.mx2 = ret.res1 = ret.res2 = ret.res1_mx = ret.res1_mn = -INF;
            ret.mn1 = ret.mn2 = INF;

            if (l == 0)
                return x;
            else if (x.l == 0)
                return *this;

            ret.l = l, ret.r = x.r;

            ret.mx1 = max(mx1, x.mx1);
            ret.mn1 = min(mn1, x.mn1);
            if (mx1 == ret.mx1)
                ret.mx2 = max(mx2, x.mx1);
            else
                ret.mx2 = max(x.mx2, mx1);
            if (mn1 == ret.mn1)
                ret.mn2 = min(mn2, x.mn1);
            else
                ret.mn2 = min(x.mn2, mn1);

            ret.res1 = max(res1, x.res1);
            ret.res1 = max(ret.res1, mx1 - x.mn1);

            ret.res2 = max(res2, x.res2);
            ret.res2 = max(ret.res2, res1 + x.res1);
            ret.res2 = max(ret.res2, res1_mx - x.mn1);
            ret.res2 = max(ret.res2, x.res1_mn + mx1);
            ret.res2 = max(ret.res2, mx1 + mx2 - x.mn1 - x.mn2);

            ret.res1_mx = max(res1_mx, x.res1_mx);
            ret.res1_mx = max(ret.res1_mx, res1 + x.mx1);
            ret.res1_mx = max(ret.res1_mx, x.res1 + mx1);
            if (r - l + 1 >= 2)
                ret.res1_mx = max(ret.res1_mx, mx1 - x.mn1 + mx2);
            if (x.r - x.l + 1 >= 2)
                ret.res1_mx = max(ret.res1_mx, mx1 - x.mn1 + x.mx1);

            ret.res1_mn = max(res1_mn, x.res1_mn);
            ret.res1_mn = max(ret.res1_mn, res1 - x.mn1);
            ret.res1_mn = max(ret.res1_mn, x.res1 - mn1);
            if (r - l + 1 >= 2)
                ret.res1_mn = max(ret.res1_mn, mx1 - x.mn1 - mn1);
            if (x.r - x.l + 1 >= 2)
                ret.res1_mn = max(ret.res1_mn, mx1 - x.mn1 - x.mn2);
            return ret;
        }

    } tree[MAXN << 2];

    void build(int p, int s, int t)
    {
        tree[p].l = s, tree[p].r = t;
        if (s == t)
        {
            tree[p].mx1 = tree[p].mn1 = 1ll * a[s] * a[s];
            tree[p].mx2 = tree[p].res1 = tree[p].res2 = tree[p].res1_mx = tree[p].res1_mn = -INF;
            tree[p].mn2 = INF;
            return;
        }
        int mid = (s + t) >> 1;
        build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    node query(int p, int s, int t)
    {
        if (tree[p].l >= s && tree[p].r <= t)
            return tree[p];
        int mid = (tree[p].l + tree[p].r) >> 1;
        node res1, res2;
        res1.l = res1.r = res2.l = res2.r = 0;
        if (s <= mid)
            res1 = query(p << 1, s, t);
        if (t > mid)
            res2 = query(p << 1 | 1, s, t);
        return res1 + res2;
    }
};

SegTree tr;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        tr.build(1, 1, n);
        while (m--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", tr.query(1, l, r).res2);
        }
    }
    return 0;
}