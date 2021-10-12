#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll T, n, m, x, a[MAXN], len;
map<ll, ll> ma;

struct node
{
    ll idx, val;
} s[MAXN];

vector<node> li[MAXN];

// MARK
ll cal(ll x)
{
    ll p = abs(s[n].val);
    return (x % p + p) % p;
}

bool cmp1(node xx, node yy)
{
    if (xx.val == yy.val)
        return xx.idx > yy.idx;
    else
        return xx.val < yy.val;
}

bool cmp2(node xx, node yy) { return xx.val < yy.val; }

void solve(bool is_greater_zero)
{
    if (!is_greater_zero)
        for (int i = 1; i <= n; i++)
            a[i] = -a[i], s[i].val = s[i - 1].val + a[i];
    for (int i = 1; i <= n; i++)
    {
        int p = cal(s[i].val);
        if (ma.find(p) == ma.end())
            ma.insert(pair<ll, ll>(p, ++len));
        li[ma[p]].emplace_back(s[i]);
    }
    for (auto b : ma)
        sort(li[b.second].begin(), li[b.second].end(), cmp1);
    while (m--)
    {
        scanf("%lld", &x);
        if (!is_greater_zero)
            x = -x;
        if (x == 0)
        {
            printf("0\n");
            continue;
        }
        int p = cal(x);
        if (ma.find(p) == ma.end())
        {
            printf("-1\n");
            continue;
        }
        ll pos = ma[p];
        ll idx = upper_bound(li[pos].begin(), li[pos].end(), node{0, x}, cmp2) - li[pos].begin();
        if (idx == 0)
        {
            printf("-1\n");
            continue;
        }
        printf("%lld\n", (x - li[pos][idx - 1].val) / s[n].val * n + li[pos][idx - 1].idx);
    }
    for (auto b : ma)
        li[b.second].clear();
}

void solve2()
{
    for (int i = 1; i <= n; i++)
        ma.insert(pair<ll, ll>(s[i].val, i));
    while (m--)
    {
        scanf("%lld", &x);
        if (x == 0)
        {
            printf("0\n");
            continue;
        }
        if (ma.find(x) == ma.end())
            printf("-1\n");
        else
            printf("%lld\n", ma[x]);
    }
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        len = 0;
        ma.clear();
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            s[i].idx = i;
            s[i].val = s[i - 1].val + a[i];
        }
        if (s[n].val > 0)
            solve(true);
        else if (s[n].val < 0)
            solve(false);
        else
            solve2();
    }
    return 0;
}