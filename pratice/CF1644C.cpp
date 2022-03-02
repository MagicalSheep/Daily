#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 10;
typedef long long ll;

int t, n, x;
ll a[MAXN], f[MAXN][MAXN];

void solve()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 0;
    for (int i = 1; i <= n; i++)
        f[i][0] = max(f[i - 1][0] + a[i], max(0LL, a[i]));
    for (int i = 1; i <= n; i++)
        for (int j = i; j >= 1; j--)
            f[i][j] = max(f[i - 1][j] + a[i], f[i - 1][j - 1] + a[i] + x);
    ll aans[n + 1];
    for (int i = 0; i <= n; i++)
        aans[i] = 0;
    for (int i = 1; i <= n; i++)
        for (int k = 0; k <= n; k++)
            aans[k] = max(aans[k], f[i][k]);
    ll ans = aans[0];
    for (int k = 0; k <= n; k++)
    {
        ans = max(ans, aans[k]);
        printf("%lld ", ans);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        solve();
    }
    return 0;
}