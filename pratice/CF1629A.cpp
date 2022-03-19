#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 10;

int t, n, k;
pair<int, int> a[MAXN];

void solve()
{
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        if (k >= a[i].first)
            k += a[i].second;
        else
            break;
    }
    printf("%d\n", k);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].first);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].second);
        solve();
    }
    return 0;
}