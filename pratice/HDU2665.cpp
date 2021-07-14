#include <bits/stdc++.h>
typedef int ll; // note: long long will cause MLE
using namespace std;
const int MAXN = 1e5 + 10;

ll tot, lson[MAXN << 5], rson[MAXN << 5], sum[MAXN << 5];
ll T, rt[MAXN], origin[MAXN];

struct node
{
    ll idx, rnk, val;
} a[MAXN];

bool cmp1(const node &a, const node &b) { return a.val < b.val; }
bool cmp2(const node &a, const node &b) { return a.idx < b.idx; }

ll update(ll p, ll s, ll t, ll k)
{
    ll rt = ++tot;
    lson[rt] = lson[p], rson[rt] = rson[p], sum[rt] = sum[p] + 1;
    if (s == t)
        return rt;
    ll mid = (s + t) >> 1;
    if (k <= mid)
        lson[rt] = update(lson[rt], s, mid, k);
    else
        rson[rt] = update(rson[rt], mid + 1, t, k);
    return rt;
}

ll query(ll p1, ll p2, ll s, ll t, ll k)
{
    if (s == t)
        return s;
    ll mid = (s + t) >> 1;
    ll d = sum[lson[p2]] - sum[lson[p1]];
    if (d >= k)
        return query(lson[p1], lson[p2], s, mid, k);
    else
        return query(rson[p1], rson[p2], mid + 1, t, k - d);
}

int main()
{
    cin >> T;
    while (T--)
    {
        tot = 0;
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].val;
            a[i].idx = i;
        }
        sort(a + 1, a + 1 + n, cmp1);
        ll rnk = 0;
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
        while (m--)
        {
            ll s, t, k;
            cin >> s >> t >> k;
            ll rnk = query(rt[s - 1], rt[t], 1, n, k);
            cout << origin[rnk] << endl;
        }
    }
    return 0;
}