# 线段树

## 基本操作

### 结构体定义

```C++
struct node
{
    ll l, r, mx, sum;
} tree[MAXN << 2];
```

### 建树

```C++
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
```

### 单点修改

```C++
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
```

### 区间修改


### 区间查询

```C++
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
```

## 多懒惰标记处理

含有多个操作时，首先建立起各运算操作的优先级关系，如：赋值操作 > 乘法操作 > 加法操作。为每个操作设立懒惰标记，在进行相关操作的时候，除了更新存储的值和对应懒惰标记外，还需要更新比其优先级更低的所有操作的懒惰标记。

如：在进行赋值操作时，还需要更新乘法和加法标记；在进行乘法操作时，还需更新加法标记；在进行加法操作时，只需更新加法标记。在下放懒惰标记的函数`pushdown`中，需要分别进行这三个操作的更新值与更新标记操作，且更新标记的规则同上。（换句话说，`pushdown`就是对孩子节点进行相同的运算操作）

> [HDU4578 Transformation](https://vjudge.net/problem/HDU-4578 "HDU4578 Transformation")

```C++
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
```

> [P3373 【模板】线段树 2](https://www.luogu.com.cn/problem/P3373 "P3373 【模板】线段树 2")

```C++
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;

ll n, m, P, a[MAXN];

struct node
{
    ll l;
    ll r;
    ll sum;
    ll add;
    ll mul;
} tree[MAXN << 2];

void build(ll l, ll r, ll p)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].mul = 1;
    if (l == r)
    {
        tree[p].sum = a[l] % P;
        return;
    }
    ll m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % P;
}

void pushdown(ll p)
{
    // should not use the style, see HDU4578
    // update son sum
    tree[p << 1].sum = (tree[p << 1].sum * tree[p].mul + ((tree[p << 1].r - tree[p << 1].l + 1) * tree[p].add) % P) % P;
    tree[p << 1 | 1].sum = (tree[p << 1 | 1].sum * tree[p].mul + ((tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1) * tree[p].add) % P) % P;
    // update son lazy tag
    tree[p << 1].mul = (tree[p << 1].mul * tree[p].mul) % P;
    tree[p << 1 | 1].mul = (tree[p << 1 | 1].mul * tree[p].mul) % P;
    tree[p << 1].add = (tree[p << 1].add * tree[p].mul + tree[p].add) % P;
    tree[p << 1 | 1].add = (tree[p << 1 | 1].add * tree[p].mul + tree[p].add) % P;
    // update father lazy tag
    tree[p].add = 0;
    tree[p].mul = 1;
}

void add(ll s, ll t, ll p, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = (tree[p].sum + (tree[p].r - tree[p].l + 1) * v) % P;
        tree[p].add = (tree[p].add + v) % P;
        return;
    }
    ll m = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (s <= m)
        add(s, t, p << 1, v);
    if (t > m)
        add(s, t, p << 1 | 1, v);
    tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % P;
}

void mul(ll s, ll t, ll p, ll v)
{
    if (tree[p].l >= s && tree[p].r <= t)
    {
        tree[p].sum = (tree[p].sum * v) % P;
        tree[p].add = (tree[p].add * v) % P;
        tree[p].mul = (tree[p].mul * v) % P;
        return;
    }
    ll m = (tree[p].l + tree[p].r) >> 1;
    pushdown(p);
    if (s <= m)
        mul(s, t, p << 1, v);
    if (t > m)
        mul(s, t, p << 1 | 1, v);
    tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % P;
}

ll query(ll s, ll t, ll p)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].sum;
    pushdown(p);
    ll ans = 0;
    ll m = (tree[p].l + tree[p].r) >> 1;
    if (s <= m)
        ans = (query(s, t, p << 1) + ans) % P;
    if (t > m)
        ans = (query(s, t, p << 1 | 1) + ans) % P;
    return ans;
}

int main()
{
    scanf("%lli%lli%lli", &n, &m, &P);
    for (int i = 1; i <= n; i++)
        scanf("%lli", &a[i]);
    build(1, n, 1);
    ll o, x, y, k;
    while (m--)
    {
        scanf("%lli", &o);
        if (o == 1)
        {
            scanf("%lli%lli%lli", &x, &y, &k);
            mul(x, y, 1, k);
        }
        else if (o == 2)
        {
            scanf("%lli%lli%lli", &x, &y, &k);
            add(x, y, 1, k);
        }
        else
        {
            scanf("%lli%lli", &x, &y);
            printf("%lli\n", query(x, y, 1));
        }
    }
    return 0;
}
```

## 应用

# 可持久化线段树