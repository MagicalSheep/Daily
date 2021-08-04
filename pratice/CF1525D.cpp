#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 5e3 + 10;

int n, a[MAXN], f[MAXN][MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            f[i][j] = INF;
    f[0][0] = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
        if (a[i] == 1)
            pos.emplace_back(i);
    int len = pos.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (f[i][j] == INF)
                continue;
            f[i + 1][j] = min(f[i + 1][j], f[i][j]);
            if (j < len && a[i] == 0)
                f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j] + abs(pos[j] - i));
        }
    }
    printf("%d\n", f[n][len]);
    return 0;
}