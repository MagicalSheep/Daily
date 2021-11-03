#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN], b[MAXN], sum[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        sort(a + 1, a + 1 + n);
        b[1] = sum[1] = a[1];
        for (int i = 2; i <= n; i++)
        {
            b[i] = sum[i] = a[i] - sum[i - 1];
            sum[i] += sum[i - 1];
        }
        sort(b + 1, b + 1 + n);
        printf("%lld\n", b[n]);
    }
    return 0;
}