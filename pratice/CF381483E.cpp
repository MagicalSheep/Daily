#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, num;
ll a[MAXN], b[MAXN], prefix[MAXN];

/** Persistent Segment Tree Begin **/
namespace PSegTree
{
    int tot, root[MAXN];

    struct node
    {
        int lson, rson, cnt;
        ll sum;
    } tree[MAXN << 5];

    int build(int s, int t)
    {
        int rt = ++tot;
        tree[rt].lson = tree[rt].rson = tree[rt].cnt = tree[rt].sum = 0;
        if (s == t)
            return rt;
        int mid = (s + t) >> 1;
        tree[rt].lson = build(s, mid);
        tree[rt].rson = build(mid + 1, t);
        return rt;
    }

    int update(int p, int l, int r, int k, int v)
    {
        int rt = ++tot;
        tree[rt] = tree[p];
        tree[rt].cnt += v;
        tree[rt].sum += b[k];
        if (l == r)
            return rt;
        int mid = (l + r) >> 1;
        if (k <= mid)
            tree[rt].lson = update(tree[rt].lson, l, mid, k, v);
        else
            tree[rt].rson = update(tree[rt].rson, mid + 1, r, k, v);
        return rt;
    }

    ll query(int p1, int p2, int l, int r, int k)
    {
        if (l == r)
            return b[l] * k;
        int mid = (l + r) >> 1;
        int cnt = tree[tree[p2].rson].cnt - tree[tree[p1].rson].cnt;
        if (cnt >= k)
            return query(tree[p1].rson, tree[p2].rson, mid + 1, r, k);
        else
            return tree[tree[p2].rson].sum - tree[tree[p1].rson].sum + query(tree[p1].lson, tree[p2].lson, l, mid, k - cnt);
    }
}
/** Persistent Segment Tree End **/

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), prefix[i] = prefix[i - 1] + a[i], b[i] = a[i];

    sort(b + 1, b + 1 + n);
    num = unique(b + 1, b + 1 + n) - b - 1;
    PSegTree::root[0] = PSegTree::build(1, num);
    for (int i = 1; i <= n; i++)
    {
        int k = lower_bound(b + 1, b + 1 + num, a[i]) - b;
        PSegTree::root[i] = PSegTree::update(PSegTree::root[i - 1], 1, num, k, 1);
    }
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        int len = r - l + 1;
        if (len & 1)
            ++len;
        ll mx = PSegTree::query(PSegTree::root[l - 1], PSegTree::root[r], 1, num, len / 2);
        ll tot = prefix[r] - prefix[l - 1];
        ll ans = mx - (tot - mx);
        printf("%lld\n", ans);
    }
    return 0;
}