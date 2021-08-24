#include <bits/stdc++.h>
using namespace std;

/** Segment Tree Begin **/
template <typename T>
class SegTree
{
private:
    int siz; // tree size
    T *a;    // source data
    struct node
    {
        int l, r;
        // data you want to operate

        /** Example Begin **/
        T mx, sum, add;
        /** Example End **/
    } * tree;

    // Merge function
    void pushup(int p)
    {
        /** Example Begin **/
        tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
        tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
        /** Example End **/
    }

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

public:
    SegTree(int max_size) { tree = (node *)calloc(max_size << 2, sizeof(node)); }
    SegTree(int max_size, T *arr) { tree = (node *)calloc(max_size << 2, sizeof(node)), this->a = arr; }

    void build(int p, int s, int t)
    {
        tree[p].l = s, tree[p].r = t;
        /** Example Begin **/
        tree[p].add = 0;
        /** Example End **/
        if (s == t)
        {
            // initialization

            /** Example Begin **/
            tree[p].mx = tree[p].sum = a[s];
            /** Example End **/
            return;
        }
        int mid = (s + t) >> 1;
        build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
        pushup(p);
    }

    // Section update
    void update(int p, int s, int t, T x)
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
        pushup(p);
    }

    // Section query
    T query(int p, int s, int t)
    {
        if (tree[p].l >= s && tree[p].r <= t)
            return tree[p].sum; // Example
        pushdown(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        T sum = 0;
        if (s <= mid)
            sum = query(p << 1, s, t);
        if (t > mid)
            sum += query(p << 1 | 1, s, t);
        return sum;
    }
};
/** Segment Tree End **/

// test variable begin
const int MAXN = 1e5 + 10;
int n, m;
long long a[MAXN];
// test variable end

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    SegTree<long long> tree(MAXN, a);
    tree.build(1, 1, n);

    int o, x, y;
    long long k;
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
            printf("%lld\n", tree.query(1, x, y));
        }
    }
    return 0;
}