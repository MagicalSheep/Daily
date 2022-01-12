#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int t, n, l, a[MAXN], bit[MAXN];

int solve()
{
    scanf("%d%d", &n, &l);
    memset(bit, 0, sizeof(bit));
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = 30; j >= 0; --j)
            if (a[i] & (1 << j))
                ++bit[j];
    int res = 0;
    for (int i = 0; i <= 30; ++i)
        if (bit[i] > n - bit[i])
            res ^= (1 << i);
    return res;
}

int main()
{
    scanf("%d", &t);
    while (t--)
        printf("%d\n", solve());
    return 0;
}