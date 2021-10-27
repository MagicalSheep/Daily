#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll t, n, a[MAXN], suf[MAXN], f[MAXN][500];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        suf[n + 1] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), f[i][0] = INT_MAX;
        for (int i = n; i >= 1; i--)
            suf[i] = suf[i + 1] + a[i];
        f[n][1] = a[n];
        ll ans = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            int len = n - i + 1;
            for (int j = 1; j <= len && j < 500; j++)
            {
                f[i][j] = f[i + 1][j];
                if ((suf[i] - suf[i + j]) < f[i + j][j - 1])
                    f[i][j] = max(f[i][j], suf[i] - suf[i + j]), ans = max(ans, 1LL * j);
            }
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= n + 1; i++)
            for (int j = 0; j < 500; j++)
                f[i][j] = 0;
    }
    return 0;
}