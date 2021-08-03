#include <bits/stdc++.h>
using namespace std;
const int maxlog = 18;
const int MAXN = 1e5 + 10;

int N, M, f[MAXN][maxlog + 5], logn[MAXN];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &f[i][0]);
    logn[0] = -1;
    for (int i = 1; i < MAXN; i++)
        logn[i] = logn[i >> 1] + 1;
    for (int j = 1; j <= maxlog; j++)
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    while (M--)
    {
        int l, r, j;
        scanf("%d%d", &l, &r);
        j = logn[r - l + 1];
        printf("%d\n", max(f[l][j], f[r - (1 << j) + 1][j]));
    }
    return 0;
}