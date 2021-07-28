#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 10;

int T, MaxP, W;
int AP[MAXN], BP[MAXN], AS[MAXN], BS[MAXN];
int f[MAXN][MAXN];

int main()
{
    scanf("%d%d%d", &T, &MaxP, &W);
    for (int i = 1; i <= T; i++)
        scanf("%d%d%d%d", &AP[i], &BP[i], &AS[i], &BS[i]);
    memset(f, -0x3f, sizeof(f));
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= AS[i]; j++)
            f[i][j] = -1 * j * AP[i];
        for (int j = 0; j <= MaxP; j++)
            f[i][j] = max(f[i][j], f[i - 1][j]);
        if (i <= W + 1)
            continue;
        int l = 1, r = 0, q[MAXN];
        for (int j = 0; j <= MaxP; j++)
        {
            while (l <= r && f[i - W - 1][q[r]] + AP[i] * q[r] <= f[i - W - 1][j] + AP[i] * j)
                r--;
            while (l <= r && q[l] < j - AS[i])
                l++;
            q[++r] = j;
            if (l <= r)
                f[i][j] = max(f[i][j], f[i - W - 1][q[l]] + AP[i] * q[l] - AP[i] * j);
        }
        l = 1, r = 0;
        for (int j = MaxP; j >= 0; j--)
        {
            while (l <= r && f[i - W - 1][q[r]] + BP[i] * q[r] <= f[i - W - 1][j] + BP[i] * j)
                r--;
            while (l <= r && q[l] > j + BS[i])
                l++;
            q[++r] = j;
            if (l <= r)
                f[i][j] = max(f[i][j], f[i - W - 1][q[l]] + BP[i] * q[l] - BP[i] * j);
        }
    }
    int ans = 0;
    for (int i = 0; i <= MaxP; i++)
        ans = max(ans, f[T][i]);
    printf("%d\n", ans);
    return 0;
}