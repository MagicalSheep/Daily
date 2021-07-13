#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll a[MAXN];

struct node
{
    ll l, r, mx, sum;
} tree[MAXN << 2];

void pushup(ll p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
}

void build(ll s, ll t, ll p)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].mx = tree[p].sum = a[s];
        return;
    }
    ll mid = (s + t) >> 1;
    build(s, mid, p << 1), build(mid + 1, t, p << 1 | 1);
    pushup(p);
}

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll sum = 0;
    if (s <= mid)
        sum = query(p << 1, s, t);
    if (t > mid)
        sum += query(p << 1 | 1, s, t);
    return sum;
}

void mod(ll p, ll s, ll t, ll x)
{
    if (x > tree[p].mx)
        return;
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum %= x;
        tree[p].mx = tree[p].sum;
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (s <= mid)
        mod(p << 1, s, t, x); // note: please use [s, t] for all functions
    if (t > mid)
        mod(p << 1 | 1, s, t, x);
    pushup(p);
}

void update(ll p, ll k, ll x)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum = tree[p].mx = x;
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        update(p << 1, k, x);
    else
        update(p << 1 | 1, k, x);
    pushup(p);
}

ll n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll l, r;
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
        else if (type == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            mod(1, l, r, x);
        }
        else
        {
            ll k, x;
            cin >> k >> x;
            update(1, k, x);
        }
    }
    return 0;
}