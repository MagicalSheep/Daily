#include <bits/stdc++.h>
#define P 10007
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;

struct node
{
    ll l;
    ll r;
    ll sum;
    ll dsum;
    ll ddsum;
    ll add;
    ll mul;
    ll set;
} tree[MAXN << 2];

void pushup(ll p)
{
    tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % P;
    tree[p].dsum = (tree[p << 1].dsum + tree[p << 1 | 1].dsum) % P;
    tree[p].ddsum = (tree[p << 1].ddsum + tree[p << 1 | 1].ddsum) % P;
}

void build(ll l, ll r, ll p)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].mul = 1;
    tree[p].set = 0;
    if (l == r)
    {
        tree[p].ddsum = tree[p].dsum = tree[p].sum = 0;
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    pushup(p);
}

void pushdown(ll p)
{
    ll len1 = tree[p << 1].r - tree[p << 1].l + 1;
    ll len2 = tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1;
    ll mul = tree[p].mul;
    ll add = tree[p].add;

    if (tree[p].set)
    {
        ll tmp = tree[p].set;
        tree[p << 1].sum = tmp * len1 % P;
        tree[p << 1 | 1].sum = tmp * len2 % P;
        tree[p << 1].dsum = tmp * tmp % P * len1 % P;
        tree[p << 1 | 1].dsum = tmp * tmp % P * len2 % P;
        tree[p << 1].ddsum = tmp * tmp % P * tmp % P * len1 % P;
        tree[p << 1 | 1].ddsum = tmp * tmp % P * tmp % P * len2 % P;
        tree[p << 1].set = tree[p << 1 | 1].set = tree[p].set;
        tree[p << 1].add = tree[p << 1 | 1].add = 0;
        tree[p << 1].mul = tree[p << 1 | 1].mul = 1;
        tree[p].set = 0;
    }
    if (mul != 1)
    {
        tree[p << 1].sum = tree[p << 1].sum * mul % P;
        tree[p << 1 | 1].sum = tree[p << 1 | 1].sum * mul % P;
        tree[p << 1].dsum = tree[p << 1].dsum * mul % P * mul % P;
        tree[p << 1 | 1].dsum = tree[p << 1 | 1].dsum * mul % P * mul % P;
        tree[p << 1].ddsum = tree[p << 1].ddsum * mul % P * mul % P * mul % P;
        tree[p << 1 | 1].ddsum = tree[p << 1 | 1].ddsum * mul % P * mul % P * mul % P;

        tree[p << 1].mul = tree[p << 1].mul * mul % P;
        tree[p << 1 | 1].mul = tree[p << 1 | 1].mul * mul % P;
        if (tree[p << 1].add)
            tree[p << 1].add = tree[p << 1].add * mul % P;
        if (tree[p << 1 | 1].add)
            tree[p << 1 | 1].add = tree[p << 1 | 1].add * mul % P;
        tree[p].mul = 1;
    }
    if (add)
    {
        tree[p << 1].ddsum = (((tree[p << 1].ddsum + 3 * add % P * tree[p << 1].dsum % P) % P + 3 * add % P * add % P * tree[p << 1].sum % P) % P + len1 * add % P * add % P * add % P) % P;
        tree[p << 1 | 1].ddsum = (((tree[p << 1 | 1].ddsum + 3 * add % P * tree[p << 1 | 1].dsum % P) % P + 3 * add % P * add % P * tree[p << 1 | 1].sum % P) % P + len2 * add % P * add % P * add % P) % P;
        tree[p << 1].dsum = ((tree[p << 1].dsum + add * add % P * len1 % P) % P + 2 * add % P * tree[p << 1].sum % P) % P;
        tree[p << 1 | 1].dsum = ((tree[p << 1 | 1].dsum + add * add % P * len2 % P) % P + 2 * add % P * tree[p << 1 | 1].sum % P) % P;
        tree[p << 1].sum = (tree[p << 1].sum + add * len1 % P) % P;
        tree[p << 1 | 1].sum = (tree[p << 1 | 1].sum + add * len2 % P) % P;
        tree[p << 1].add = (tree[p << 1].add + add) % P;
        tree[p << 1 | 1].add = (tree[p << 1 | 1].add + add) % P;
        tree[p].add = 0;
    }
}

void add(ll s, ll t, ll p, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        ll len = tree[p].r - tree[p].l + 1;
        tree[p].ddsum = (((tree[p].ddsum + 3 * v % P * tree[p].dsum % P) % P + 3 * v % P * v % P * tree[p].sum) % P + v * v % P * v % P * len % P) % P;
        tree[p].dsum = ((tree[p].dsum + 2 * v % P * tree[p].sum % P) % P + v * v % P * len % P) % P;
        tree[p].sum = (tree[p].sum + len * v % P) % P;
        tree[p].add = (tree[p].add + v) % P;
        return;
    }
    ll m = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (s <= m)
        add(s, t, p << 1, v);
    if (t > m)
        add(s, t, p << 1 | 1, v);
    pushup(p);
}

void mul(ll s, ll t, ll p, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = tree[p].sum * v % P;
        tree[p].dsum = tree[p].dsum * v % P * v % P;
        tree[p].ddsum = tree[p].ddsum * v % P * v % P * v % P;
        tree[p].add = tree[p].add * v % P;
        tree[p].mul = tree[p].mul * v % P;
        return;
    }
    ll m = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (s <= m)
        mul(s, t, p << 1, v);
    if (t > m)
        mul(s, t, p << 1 | 1, v);
    pushup(p);
}

void change(ll s, ll t, ll p, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        ll len = tree[p].r - tree[p].l + 1;
        tree[p].sum = v * len % P;
        tree[p].dsum = v * v % P * len % P;
        tree[p].ddsum = v * v % P * v % P * len % P;
        tree[p].add = 0;
        tree[p].mul = 1;
        tree[p].set = v;
        return;
    }
    ll m = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (s <= m)
        change(s, t, p << 1, v);
    if (t > m)
        change(s, t, p << 1 | 1, v);
    pushup(p);
}

ll query(ll s, ll t, ll p, ll type)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        if (type == 1)
            return tree[p].sum % P;
        else if (type == 2)
            return tree[p].dsum % P;
        else
            return tree[p].ddsum % P;
    }
    pushdown(p);
    ll ans = 0;
    ll m = (tree[p].l + tree[p].r) >> 1;
    if (s <= m)
        ans = (query(s, t, p << 1, type) + ans) % P;
    if (t > m)
        ans = (query(s, t, p << 1 | 1, type) + ans) % P;
    return ans;
}

ll N, M;

int main()
{
    while (1)
    {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        build(1, N, 1);
        while (M--)
        {
            ll o, x, y, c;
            cin >> o >> x >> y >> c;
            if (o == 1)
                add(x, y, 1, c);
            else if (o == 2)
                mul(x, y, 1, c);
            else if (o == 3)
                change(x, y, 1, c);
            else
                cout << query(x, y, 1, c) % P << endl;
        }
    }
    return 0;
}