#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

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
    int N, M;
    scanf("%d%d", &N, &M);
    int a[MAXN];
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    ST::init(a, N);
    while (M--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", ST::query(l, r));
    }
    return 0;
}