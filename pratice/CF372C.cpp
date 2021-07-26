#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 150000 + 10;

ll n, m, d, f[MAXN];

struct node
{
    int l, r;
    ll mx;
} tree[MAXN << 2];

struct fire
{
    int a, b, t;
} ff[300 + 10];

void build(int p, int s, int t)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].mx = f[s];
        return;
    }
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
}

ll query(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].mx;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (t <= mid)
        return query(p << 1, s, t);
    else if (s > mid)
        return query(p << 1 | 1, s, t);
    else
        return max(query(p << 1, s, t), query(p << 1 | 1, s, t));
}

inline ll g(int i, int j) { return ff[i].b - abs(ff[i].a - j); }

int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &d);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &ff[i].a, &ff[i].b, &ff[i].t);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        ll dk = (ff[i].t - ff[i - 1].t) * d;
        for (ll j = 1; j <= n; j++)
            f[j] = query(1, max(1ll, j - dk), min(n, j + dk)) + g(i, j);
        build(1, 1, n);
    }
    printf("%I64d\n", query(1, 1, n));
    return 0;
}