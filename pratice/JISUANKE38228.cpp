#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 5e5 + 10;

ll a[MAXN], n, l[MAXN], r[MAXN], sum[MAXN];

struct node
{
    int l, r, mx, mn;
} tree[MAXN << 2];

void pushup(int p)
{
    tree[p].mn = min(tree[p << 1].mn, tree[p << 1 | 1].mn);
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
}

void build(int p, int s, int t)
{
    tree[p].l = s;
    tree[p].r = t;
    if (s == t)
    {
        tree[p].mx = tree[p].mn = sum[s];
        return;
    }
    int mid = (s + t) >> 1;
    build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
    pushup(p);
}

ll getmin(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].mn;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (t <= mid)
        return getmin(p << 1, s, t);
    else if (s > mid)
        return getmin(p << 1 | 1, s, t);
    else
        return min(getmin(p << 1, s, t), getmin(p << 1 | 1, s, t));
}

ll getmax(int p, int s, int t)
{
    if (tree[p].l >= s && tree[p].r <= t)
        return tree[p].mx;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (t <= mid)
        return getmax(p << 1, s, t);
    else if (s > mid)
        return getmax(p << 1 | 1, s, t);
    else
        return max(getmax(p << 1, s, t), getmax(p << 1 | 1, s, t));
}

inline ll getsum(int s, int t)
{
    return sum[t] - sum[s - 1];
}

void presolve()
{
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        l[i] = (s.empty()) ? 1 : s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        r[i] = (s.empty()) ? n : s.top() - 1;
        s.push(i);
    }
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
    ll ans = -0x3f3f3f3f;
    build(1, 1, n);
    presolve();
    for (int i = 1; i <= n; i++)
        ans = max(ans, a[i] * ((a[i] >= 0) ? getsum(l[i], r[i]) : (getmin(1, i, r[i]) - getmax(1, l[i], i))));
    printf("%lld\n", ans);
    return 0;
}