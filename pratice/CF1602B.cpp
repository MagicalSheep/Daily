#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;

int t, n, q;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int his[25][MAXN], cnt[25][MAXN];
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &his[0][i]);
            cnt[0][his[0][i]]++;
        }
        int kk = 1;
        for (; kk < 25; kk++)
        {
            bool is_same = true;
            for (int i = 1; i <= n; i++)
            {
                his[kk][i] = cnt[kk - 1][his[kk - 1][i]];
                cnt[kk][his[kk][i]]++;
                if (his[kk][i] != his[kk - 1][i])
                    is_same = false;
            }
            if (is_same)
                break;
        }
        scanf("%d", &q);
        while (q--)
        {
            int x, k;
            scanf("%d%d", &x, &k);
            if (k >= kk)
                printf("%d\n", his[kk][x]);
            else
                printf("%d\n", his[k][x]);
        }
    }
    return 0;
}