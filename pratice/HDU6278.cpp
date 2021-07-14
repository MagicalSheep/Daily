#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, q, lson[MAXN << 5], rson[MAXN << 5], sum[MAXN << 5], tot;
int rt[MAXN], origin[MAXN];

struct node
{
    int idx, val, rnk;
} a[MAXN];

bool cmp1(const node &a, const node &b) { return a.val < b.val; }
bool cmp2(const node &a, const node &b) { return a.idx < b.idx; }

int update(int p, int s, int t, int k)
{
    int rt = ++tot;
    lson[rt] = lson[p], rson[rt] = rson[p], sum[rt] = sum[p] + 1;
    if (s == t)
        return rt;
    int mid = (s + t) >> 1;
    if (k <= mid)
        lson[rt] = update(lson[rt], s, mid, k);
    else
        rson[rt] = update(rson[rt], mid + 1, t, k);
    return rt;
}

int query(int p1, int p2, int s, int t, int k)
{
    if (s == t)
        return origin[s];
    int mid = (s + t) >> 1;
    int d = sum[lson[p2]] - sum[lson[p1]];
    if (k <= d)
        return query(lson[p1], lson[p2], s, mid, k);
    else
        return query(rson[p1], rson[p2], mid + 1, t, k - d);
}

int main()
{
    while (cin >> n >> q)
    {
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].val;
            a[i].idx = i;
        }
        sort(a + 1, a + 1 + n, cmp1);
        int rnk = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i != 1 && a[i].val == a[i - 1].val)
                a[i].rnk = a[i - 1].rnk;
            else
                a[i].rnk = ++rnk;
        }
        sort(a + 1, a + 1 + n, cmp2);
        for (int i = 1; i <= n; i++)
        {
            rt[i] = update(rt[i - 1], 1, n, a[i].rnk);
            origin[a[i].rnk] = a[i].val;
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int pl = 1, pr = r - l + 1, ans;
            while (pl <= pr)
            {
                int mid = (pl + pr) >> 1;
                // note: k-th small to k-th big -- len - k + 1
                if (query(rt[l - 1], rt[r], 1, n, r - l + 2 - mid) >= mid)
                {
                    ans = mid;
                    pl = mid + 1;
                }
                else
                {
                    pr = mid - 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}