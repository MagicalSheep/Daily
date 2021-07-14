#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;

int tot, a[MAXN], n, m, rt[MAXN], tim;

struct node
{
    int l, r, lson, rson;
    ll sum, add;
} tree[MAXN << 5];

int build(int s, int t)
{
    int rt = ++tot;
    tree[rt].l = s;
    tree[rt].r = t;
    tree[rt].lson = tree[rt].rson = tree[rt].add = 0;
    if (s == t)
    {
        tree[rt].sum = a[s];
        return rt;
    }
    int mid = (s + t) >> 1;
    tree[rt].lson = build(s, mid);
    tree[rt].rson = build(mid + 1, t);
    tree[rt].sum = tree[tree[rt].lson].sum + tree[tree[rt].rson].sum;
    return rt;
}

int update(int p, int s, int t, ll v)
{
    int rt = ++tot;
    tree[rt] = tree[p];
    tree[rt].sum += v * (min(tree[rt].r, t) - max(tree[rt].l, s) + 1); // note: update all the sum on the way
    if (tree[rt].l >= s && tree[rt].r <= t)
    {
        tree[rt].add += v; // note: sum has been updated above, so just update the tag
        return rt;
    }
    int mid = (tree[rt].r + tree[rt].l) >> 1;
    if (s <= mid)
        tree[rt].lson = update(tree[rt].lson, s, t, v);
    if (t > mid)
        tree[rt].rson = update(tree[rt].rson, s, t, v);
    // note: sum has been updated above, so don't have to push up
    return rt;
}

ll query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    int mid = (tree[p].r + tree[p].l) >> 1;
    ll ans = tree[p].add * (min(tree[p].r, t) - max(tree[p].l, s) + 1); // note: smaller field
    // sum all the tag on the way
    if (s <= mid)
        ans += query(tree[p].lson, s, t);
    if (t > mid)
        ans += query(tree[p].rson, s, t);
    return ans;
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        tot = 0;
        tim = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        rt[0] = build(1, n);
        while (m--)
        {
            char o[2];
            scanf("%s", &o);
            if (o[0] == 'C')
            {
                int l, r;
                ll d;
                scanf("%d%d%lld", &l, &r, &d);
                rt[tim + 1] = update(rt[tim], l, r, d);
                ++tim;
            }
            else if (o[0] == 'Q')
            {
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%lld\n", query(rt[tim], l, r));
            }
            else if (o[0] == 'H')
            {
                int l, r, t;
                scanf("%d%d%d", &l, &r, &t);
                printf("%lld\n", query(rt[t], l, r));
            }
            else
            {
                scanf("%d", &tim);
                tot = rt[tim + 1]; // note: recyle memory (important)
            }
        }
    }
    return 0;
}