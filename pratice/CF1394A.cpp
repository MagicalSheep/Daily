#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll n, d, m, a[MAXN], b[MAXN], n1, n2;

int main()
{
    scanf("%lld%lld%lld", &n, &d, &m);
    for (int i = 1; i <= n; i++)
    {
        ll in;
        scanf("%lld", &in);
        (in <= m) ? a[++n1] = in : b[++n2] = in;
    }
    sort(a + 1, a + 1 + n1, greater<ll>());
    sort(b + 1, b + 1 + n2, greater<ll>());
    for (int i = 1; i <= n1; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n2; i++)
        b[i] += b[i - 1];
    ll ans = 0;
    for (int i = 0; i <= n2; i++)
    {
        ll j = n - (i - 1) * (d + 1) - 1;
        if (j >= 0)
            ans = max(ans, b[i] + a[min(j, n1)]);
        else
            break;
    }
    printf("%lld\n", ans);
    return 0;
}