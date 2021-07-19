#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int MAXN = 1e5 + 10;

int tot, root[MAXN];
int add_cnt, cut_cnt, add[25], cut[25];
int n, m, aa[MAXN], origin[MAXN << 1], len;

struct ques
{
    int type, x, y, k;
} q[MAXN];

struct node
{
    int lson, rson, val;
} tree[MAXN << 8];

void update(int &rt, int l, int r, int k, int v)
{
    if (!rt)
        rt = ++tot;
    tree[rt].val += v;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (k <= mid)
        update(tree[rt].lson, l, mid, k, v);
    else
        update(tree[rt].rson, mid + 1, r, k, v);
}

int query(int l, int r, int k)
{
    if (l == r)
        return l;
    int sum = 0;
    int mid = (l + r) >> 1;
    for (int i = 1; i <= add_cnt; i++)
        sum += tree[tree[add[i]].lson].val;
    for (int i = 1; i <= cut_cnt; i++)
        sum -= tree[tree[cut[i]].lson].val;
    if (k <= sum)
    {
        for (int i = 1; i <= add_cnt; i++)
            add[i] = tree[add[i]].lson;
        for (int i = 1; i <= cut_cnt; i++)
            cut[i] = tree[cut[i]].lson;
        return query(l, mid, k);
    }
    else
    {
        for (int i = 1; i <= add_cnt; i++)
            add[i] = tree[add[i]].rson;
        for (int i = 1; i <= cut_cnt; i++)
            cut[i] = tree[cut[i]].rson;
        return query(mid + 1, r, k - sum);
    }
}

void Add(int k, int v)
{
    int x = lower_bound(origin + 1, origin + len + 1, aa[k]) - origin;
    for (int i = k; i <= n; i += lowbit(i))
        update(root[i], 1, len, x, v);
}

int Query(int l, int r, int k)
{
    memset(add, 0, sizeof(add));
    memset(cut, 0, sizeof(cut));
    add_cnt = cut_cnt = 0;
    for (int i = r; i; i -= lowbit(i))
        add[++add_cnt] = root[i];
    for (int i = l - 1; i; i -= lowbit(i))
        cut[++cut_cnt] = root[i];
    return query(1, len, k);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &aa[i]), origin[++len] = aa[i];
    for (int i = 1; i <= m; i++)
    {
        int x, y, k;
        char o[5];
        scanf("%s", o);
        if (o[0] == 'Q')
        {
            scanf("%d%d%d", &x, &y, &k);
            q[i].type = 1, q[i].x = x, q[i].y = y, q[i].k = k;
        }
        else
        {
            scanf("%d%d", &x, &y);
            q[i].type = 2, q[i].x = x, q[i].y = y;
            origin[++len] = y;
        }
    }
    sort(origin + 1, origin + 1 + len);
    len = unique(origin + 1, origin + 1 + len) - origin - 1;
    for (int i = 1; i <= n; i++)
        Add(i, 1);
    for (int i = 1; i <= m; i++)
    {
        if (q[i].type == 1)
        {
            printf("%d\n", origin[Query(q[i].x, q[i].y, q[i].k)]);
        }
        else
        {
            Add(q[i].x, -1);
            aa[q[i].x] = q[i].y;
            Add(q[i].x, 1);
        }
    }
    return 0;
}