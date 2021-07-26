#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int f[MAXN][MAXN * 20], g[MAXN][MAXN * 20], n;

struct thing
{
    int idx, t, d, p;
} a[MAXN];

bool cmp(const thing &x, const thing &y) { return x.d < y.d; }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        a[i].idx = i;
        scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p);
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            f[i][j] = max(f[i][j], f[i - 1][j]);
            if (j < a[i].d && j >= a[i].t && f[i][j] < f[i - 1][j - a[i].t] + a[i].p)
                f[i][j] = f[i - 1][j - a[i].t] + a[i].p, g[i][j] = 1;
        }
    }
    int ans = 0, tot_time = 0;
    vector<int> items;
    for (int i = 1; i <= 2000; i++)
    {
        if (ans < f[n][i])
        {
            ans = f[n][i];
            tot_time = i;
        }
    }
    printf("%d\n", ans);
    for (int i = n; i >= 1; i--)
    {
        if (g[i][tot_time])
        {
            items.emplace_back(a[i].idx);
            tot_time -= a[i].t;
        }
    }
    printf("%d\n", items.size());
    for (vector<int>::reverse_iterator it = items.rbegin(); it != items.rend(); ++it)
        printf("%d ", *it);
    printf("\n");
    return 0;
}