#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll n, a[MAXN], f[MAXN];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        f[i] = max(f[i - 1] + a[i], a[i]);
    ll ans = -0x3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}