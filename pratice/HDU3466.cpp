#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int MAXM = 5e3 + 10;

int N, M, f[MAXM];

struct obj
{
    int p, q, v;
} a[MAXN];

bool cmp(obj x, obj y) { return x.p - x.q < y.p - y.q; }

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        for (int i = 1; i <= N; i++)
            scanf("%d%d%d", &a[i].p, &a[i].q, &a[i].v);
        sort(a + 1, a + 1 + N, cmp);
        for (int i = 1; i <= N; i++)
            for (int j = M; j >= a[i].p; j--)
                if (M - j + a[i].p >= a[i].q)
                    f[j] = max(f[j], f[j - a[i].p] + a[i].v);
        int ans = 0;
        for (int j = 0; j <= M; j++)
            ans = max(ans, f[j]);
        printf("%d\n", ans);
        memset(f, 0, sizeof(f));
    }
    return 0;
}