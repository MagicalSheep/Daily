#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n, sum[MAXN];

struct obj
{
    int v, k;
} a[MAXN];

bool cmp(obj x, obj y) { return x.v < y.v; }

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            a[i].v = 0;
            scanf("%d", &a[i].k);
            for (int j = 1; j <= a[i].k; j++)
            {
                int in = 0;
                scanf("%d", &in);
                a[i].v = max(a[i].v, in + 2 - j);
            }
        }
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i].k;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, a[i].v - sum[i - 1]);
        printf("%d\n", ans);
    }
    return 0;
}