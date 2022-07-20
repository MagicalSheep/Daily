#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1025;

int t, n, m, v[MAXN], w[MAXN];
bitset<MAXN> bs[2][MAXN];

void solve()
{
    bs[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 1024; j++)
            bs[1][j] = bs[0][j] << v[i];
        for (int j = 0; j < 1024; j++)
            bs[0][j] |= bs[1][j ^ w[i]];
    }
    for (int i = 1023; i >= 0; i--)
    {
        if (bs[0][i][m])
        {
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &w[i]);
        solve();
        for (int j = 0; j < MAXN; j++)
            bs[0][j].reset();
    }
    return 0;
}