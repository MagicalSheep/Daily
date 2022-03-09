#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, d, a[MAXN];

int solve(int c)
{
    if (c <= 0)
        return 0;
    int mx = 0, ll;
    for (int i = 1; i <= n; i++)
        if (mx < a[i] - a[i - 1] - 1)
            mx = a[i] - a[i - 1] - 1, ll = a[i - 1];
    if (mx < a[c + 1] - a[c - 1] - 1)
        mx = a[c + 1] - a[c - 1] - 1, ll = a[c - 1];
    int ret = 0x3f3f3f3f;
    vector<int> tt;
    tt.emplace_back(0);
    int xx = min(mx / 2, mx - mx / 2 - 1);
    if (a[n] != d && ((c != n && d - a[n] - 1 > xx) || (c == n && d - a[n - 1] - 1 > xx)))
        tt.emplace_back(d);
    else
        tt.emplace_back(ll + xx + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i == c)
            continue;
        tt.emplace_back(a[i]);
    }
    sort(tt.begin(), tt.end());
    for (int i = 1; i < tt.size(); i++)
        ret = min(ret, tt[i] - tt[i - 1] - 1);
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int mn = 0x3f3f3f3f, l, r;
        scanf("%d%d", &n, &d);
        a[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] - a[i - 1] - 1 < mn)
                l = i - 1, r = i, mn = a[i] - a[i - 1] - 1;
        }
        int ans = max(solve(l), solve(r));
        printf("%d\n", ans);
    }
    return 0;
}