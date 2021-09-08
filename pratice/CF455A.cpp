#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll n, a[MAXN], b[MAXN], N, f[MAXN][2];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        ll in;
        scanf("%lld", &in);
        if (!b[in])
            a[++N] = in;
        ++b[in];
    }
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i++)
    {
        if (a[i - 1] + 1 == a[i])
            f[i][1] = f[i - 1][0] + a[i] * b[a[i]];
        else
            f[i][1] = max(f[i - 1][1], f[i - 1][0]) + a[i] * b[a[i]];
        f[i][0] = max(f[i - 1][1], f[i - 1][0]);
    }
    ll ans = max(f[N][1], f[N][0]);
    printf("%lld\n", ans);
}