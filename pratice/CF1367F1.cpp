#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;

int t, n;

struct obj
{
    int idx, val;
} a[MAXN];

bool cmp(obj x, obj y) { return x.val < y.val; }

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].val), a[i].idx = i;
        sort(a + 1, a + 1 + n, cmp);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int lastpos = 0, tmp = 0;
            for (int j = i; j <= n && a[j].idx > lastpos; j++)
                tmp += 1, lastpos = a[j].idx;
            ans = max(ans, tmp);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}