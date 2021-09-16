#include <bits/stdc++.h>
#define INF 0x7ffffffffff
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 10;

ll n, a[MAXN], f[MAXN];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), f[i] = -INF;
    f[0] = 0;
    f[1] = (a[1] < 0) ? -INF : a[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            f[j] = max(f[j], f[j - 1] + a[i]);
            if (f[j] < 0)
                f[j] = -INF;
        }
    }
    ll ans = 0;
    for (int i = n; i >= 0; i--)
    {
        if (f[i] >= 0)
        {
            ans = i;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}