#include <bits/stdc++.h>
#define INF 0x7fffffffffffffff
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 10;

int t, n, rkcnt;
ll a[MAXN], prefix[MAXN], f[MAXN];
unordered_map<ll, int> rk;

template <typename T>
class SegTree
{
private:
    int siz;
    struct node
    {
        int l, r;
        T mx;
    } * tree;

    void pushup(int p)
    {
        tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    }

public:
    SegTree(int max_size) { tree = (node *)calloc(max_size << 2, sizeof(node)); }

    void build(int p, int s, int t)
    {
        tree[p].l = s, tree[p].r = t;
        if (s == t)
        {
            tree[p].mx = -INF;
            return;
        }
        int mid = (s + t) >> 1;
        build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
        pushup(p);
    }

    void update(int p, int s, int t, T x)
    {
        if (tree[p].l >= s && tree[p].r <= t)
        {
            tree[p].mx = max(tree[p].mx, x);
            return;
        }
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (s <= mid)
            update(p << 1, s, t, x);
        if (t > mid)
            update(p << 1 | 1, s, t, x);
        pushup(p);
    }

    T query(int p, int s, int t)
    {
        if (s > t)
            return -INF;
        if (tree[p].l >= s && tree[p].r <= t)
            return tree[p].mx; // Example
        int mid = (tree[p].l + tree[p].r) >> 1;
        T mx = -INF;
        if (s <= mid)
            mx = max(mx, query(p << 1, s, t));
        if (t > mid)
            mx = max(mx, query(p << 1 | 1, s, t));
        return mx;
    }

    void clear()
    {
        free(tree);
    }
};

void solve()
{
    SegTree<ll> tr1(n + 1), tr2(n + 1), tr3(n + 1);
    tr1.build(1, 1, n), tr2.build(1, 1, n), tr3.build(1, 1, n);
    for (int i = 1; i <= n; i++)
        f[i] = -INF;
    if (prefix[1] > 0)
        f[1] = 1;
    else if (prefix[1] == 0)
        f[1] = 0;
    else
        f[1] = -1;
    tr1.update(1, rk[prefix[1]], rk[prefix[1]], f[1] - 1);
    tr2.update(1, rk[prefix[1]], rk[prefix[1]], f[1]);
    tr3.update(1, rk[prefix[1]], rk[prefix[1]], f[1] + 1);
    for (int i = 2; i <= n; i++)
    {
        if (prefix[i] > 0)
        {
            f[i] = i;
        }
        else
        {
            ll fj = tr1.query(1, 1, rk[prefix[i]] - 1);
            if (fj != -INF)
                f[i] = fj + i;
            f[i] = max(f[i], tr2.query(1, rk[prefix[i]], rk[prefix[i]]));
            fj = tr3.query(1, rk[prefix[i]] + 1, rkcnt);
            if (fj != -INF)
                f[i] = max(f[i], fj - i);
        }
        tr1.update(1, rk[prefix[i]], rk[prefix[i]], f[i] - i);
        tr2.update(1, rk[prefix[i]], rk[prefix[i]], f[i]);
        tr3.update(1, rk[prefix[i]], rk[prefix[i]], f[i] + i);
    }
    printf("%lld\n", f[n]);
    tr1.clear(), tr2.clear(), tr3.clear();
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        rk.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), prefix[i] = prefix[i - 1] + a[i];
        vector<ll> vec;
        for (int i = 1; i <= n; i++)
            vec.emplace_back(prefix[i]);
        sort(vec.begin(), vec.end());
        rkcnt = unique(vec.begin(), vec.end()) - vec.begin();
        for (int i = 0; i < rkcnt; i++)
            rk[vec[i]] = i + 1;
        solve();
    }
    return 0;
}