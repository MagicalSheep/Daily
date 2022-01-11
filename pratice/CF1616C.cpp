#include <bits/stdc++.h>
using namespace std;
const int MAXN = 70 + 10;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (n == 1 || n == 2)
        {
            printf("0\n");
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                double delta = ((double)(a[j] - a[i])) / (j - i);
                int cnt = 0;
                for (int k = 1; k <= n; k++)
                {
                    double val = 0;
                    if (k <= i)
                        val = a[i] - delta * (i - k);
                    else
                        val = a[i] + delta * (k - i);
                    if (abs(val - a[k]) >= 0.000000000001)
                        ++cnt;
                }
                ans = min(ans, cnt);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if (a[j] != a[i])
                    ++cnt;
            ans = min(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}