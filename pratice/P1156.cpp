#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 3e3 + 10;

// f(i, j) 处理到第i个垃圾，所处高度为j时的最长存活时间
int D, G, f[MAXM], ans;

struct rub
{
    int t, f, h;
} a[MAXN];

bool cmp(rub x, rub y) { return x.t < y.t; }

int main()
{
    scanf("%d%d", &D, &G);
    for (int i = 1; i <= G; i++)
        scanf("%d%d%d", &a[i].t, &a[i].f, &a[i].h);
    sort(a + 1, a + 1 + G, cmp);
    f[0] = 10;
    int i = 1;
    for (; i <= G; i++)
    {
        bool isok = false;
        for (int j = D; j >= 0; j--)
        {
            if (f[j] < a[i].t)
                continue;
            if (j + a[i].h >= D)
            {
                printf("%d\n", a[i].t);
                return 0;
            }
            isok = true;
            f[j + a[i].h] = max(f[j + a[i].h], f[j]);
            f[j] = max(f[j], f[j] + a[i].f);
        }
        if (!isok)
            break;
    }
    for (int j = 0; j < D; j++)
        ans = max(ans, f[j]);
    printf("%d\n", ans);
    return 0;
}