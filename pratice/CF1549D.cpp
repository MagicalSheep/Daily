#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int t, n;
ll a[MAXN], b[MAXN], lo[MAXN], f[MAXN][40];

ll query(int l, int r)
{
    ll k = lo[r - l + 1];
    return __gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

void prework()
{
    lo[0] = -1;
    for (int i = 1; i < n; i++)
        lo[i] = lo[i >> 1] + 1;
    for (int j = 1; j <= lo[n - 1]; j++)
        for (int i = 1; i + (1 << j) - 1 <= n - 1; i++)
            f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%I64d", &a[i]);
        if (n == 1)
        {
            printf("1\n");
            continue;
        }
        for (int i = 1; i < n; i++)
        {
            b[i] = abs(a[i + 1] - a[i]);
            f[i][0] = b[i];
        }
        prework();
        int j = 1;
        ll ans = 0;
        for (int i = 1; i < n; i++)
        {
            while (j <= i && query(j, i) == 1)
                j++;
            ans = max(ans, 1ll * (i - j + 2));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}