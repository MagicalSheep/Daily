#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n;

struct obj
{
    int pos, val;
} a[MAXN], b[MAXN];

bool cmp(obj x, obj y) { return x.val < y.val; }

/** Sparse Table Begin **/
namespace ST
{
    const int maxlog = 20;
    int f[MAXN][maxlog + 5], logn[MAXN];

    // begin at index 1
    void init(obj *a, int len)
    {
        for (int i = 1; i <= len; i++)
            f[i][0] = a[i].pos;
        logn[0] = -1;
        for (int i = 1; i < MAXN; i++)
            logn[i] = logn[i >> 1] + 1;
        for (int j = 1; j <= maxlog; j++)
            for (int i = 1; i + (1 << j) - 1 <= len; i++)
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }

    // begin at index 1
    int query(int l, int r)
    {
        int j = logn[r - l + 1];
        return min(f[l][j], f[r - (1 << j) + 1][j]);
    }
}
/** Sparse Table End **/

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].val), a[i].pos = i;
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i].val), b[i].pos = i;
        sort(a + 1, a + 1 + n, cmp);
        ST::init(a, n);
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            int ind = upper_bound(a + 1, a + 1 + n, b[i], cmp) - a - 1;
            int pos = ST::query(1, ind);
            ans = min(ans, i + pos - 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}