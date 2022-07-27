#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// test variable begin
const int MAXN = 1e5 + 10;
int n, m;
ll a[MAXN];
// test variable end

/** Segment Tree Begin **/
struct SegTree
{
    struct node
    {
        int l, r;
        // data you want to operate

        /** Example Begin **/
        ll mx, sum, add;
        /** Example End **/

        // Merge function
        node operator+(node &x)
        {
            node ret;
            ret.l = ret.r = ret.mx = ret.sum = ret.add = 0;

            if (l == 0)
                return x;
            else if (x.l == 0)
                return *this;

            ret.l = l, ret.r = x.r;

            /** Example Begin **/
            ret.sum = sum + x.sum;
            ret.mx = max(mx, x.mx);
            /** Example End **/

            return ret;
        }
    } tree[MAXN << 2];

    void pushdown(int p)
    {
        /** Example Begin **/
        if (tree[p].add)
        {
            tree[p << 1].add += tree[p].add;
            tree[p << 1 | 1].add += tree[p].add;
            tree[p << 1].mx += tree[p].add;
            tree[p << 1 | 1].mx += tree[p].add;
            tree[p << 1].sum += tree[p].add * (tree[p << 1].r - tree[p << 1].l + 1);
            tree[p << 1 | 1].sum += tree[p].add * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
            tree[p].add = 0;
        }
        /** Example End **/
    }

    void build(int p, int s, int t)
    {
        tree[p].l = s, tree[p].r = t;
        if (s == t)
        {
            // initialization

            /** Example Begin **/
            tree[p].add = 0;
            tree[p].mx = tree[p].sum = a[s];
            /** Example End **/
            return;
        }
        int mid = (s + t) >> 1;
        build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    // Section update
    void update(int p, int s, int t, ll x)
    {
        if (tree[p].l >= s && tree[p].r <= t)
        {
            /** Example Begin **/
            tree[p].add += x;
            tree[p].mx += x;
            tree[p].sum += x * (tree[p].r - tree[p].l + 1);
            /** Example End **/
            return;
        }
        pushdown(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (s <= mid)
            update(p << 1, s, t, x);
        if (t > mid)
            update(p << 1 | 1, s, t, x);
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }

    // Section query - node
    node query(int p, int s, int t)
    {
        if (tree[p].l >= s && tree[p].r <= t)
            return tree[p];
        pushdown(p);
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
/** Segment Tree End **/

SegTree tree;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    tree.build(1, 1, n);
    int o, x, y;
    ll k;
    while (m--)
    {
        scanf("%d", &o);
        if (o == 1)
        {
            scanf("%d%d%lld", &x, &y, &k);
            tree.update(1, x, y, k);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", tree.query(1, x, y).sum);
        }
    }
    return 0;
}