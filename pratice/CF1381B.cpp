#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e3 + 10;

int t, n, p[MAXN], pos[MAXN], arr[MAXN], tail, len, f[MAXN];

/** Sparse Table Begin **/
namespace ST
{
    const int maxlog = 20;
    int f[MAXN][maxlog + 5], logn[MAXN];

    // begin at index 1
    void init(int *a, int len)
    {
        for (int i = 1; i <= len; i++)
            f[i][0] = a[i];
        logn[0] = -1;
        for (int i = 1; i < MAXN; i++)
            logn[i] = logn[i >> 1] + 1;
        for (int j = 1; j <= maxlog; j++)
            for (int i = 1; i + (1 << j) - 1 <= len; i++)
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
    // begin at index 1
    int query(int l, int r)
    {
        int j = logn[r - l + 1];
        return max(f[l][j], f[r - (1 << j) + 1][j]);
    }
}
/** Sparse Table End **/

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++)
            scanf("%d", &p[i]), pos[p[i]] = i;
        ST::init(p, 2 * n);
        tail = 2 * n;
        while (tail >= 1)
        {
            int mx = ST::query(1, tail);
            arr[++len] = tail - pos[mx] + 1;
            tail = pos[mx] - 1;
        }
        f[0] = 1;
        for (int i = 1; i <= len; i++)
            for (int j = n; j >= arr[i]; j--)
                f[j] = f[j] || f[j - arr[i]];
        printf((f[n]) ? "YES\n" : "NO\n");
        len = 0;
        memset(f, 0, sizeof(f));
    }
    return 0;
}