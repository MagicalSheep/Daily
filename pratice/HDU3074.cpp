#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007

const int MAXN = 5e4 + 10;

ll a[MAXN];

struct node
{
    ll l, r, ans;
} tree[MAXN << 2];

ll T;

void pushup(ll p)
{
    tree[p].ans = tree[p << 1].ans * tree[p << 1 | 1].ans % MOD;
}

void build(ll p, ll s, ll t)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].ans = a[s];
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

ll query(ll p, ll s, ll t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].ans;
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll ans = 1;
    if (s <= mid)
        ans = (ans * query(p << 1, s, t)) % MOD;
    if (t > mid)
        ans = (ans * query(p << 1 | 1, s, t)) % MOD;
    return ans;
}

void update(ll p, ll k, ll x)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].ans = x;
        return;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (k <= mid)
        update(p << 1, k, x);
    else
        update(p << 1 | 1, k, x);
    pushup(p);
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        ll n;
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        build(1, 1, n);
        ll q;
        scanf("%lld", &q);
        while (q--)
        {
            ll cmd, k1, k2;
            scanf("%lld%lld%lld", &cmd, &k1, &k2);
            if (cmd == 0)
                cout << query(1, k1, k2) % MOD << endl;
            else
                update(1, k1, k2);
        }
    }
    return 0;
}