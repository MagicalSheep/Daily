#include <bits/stdc++.h>
#define INF 0xffffffffffffff
typedef long long ll;
using namespace std;
const int MAXN = 3e5 + 10;

ll n, m, k, a[MAXN], f[MAXN], sum[MAXN];

int main()
{
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        ll tmp = -INF;
        for (int j = i; j >= 0 && j >= i - m; j--)
            tmp = max(tmp, f[j] + sum[i] - sum[j] - k);
        f[i] = max(0LL, max(a[i] - k, tmp));
    }
    ll ans = -INF;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    printf("%I64d\n", ans);
    return 0;
}