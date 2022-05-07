#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30 + 5;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        int ans = 0;
        bool ok = !(a[n] == 0);
        for (int i = n - 1; i >= 1 && ok; i--)
        {
            if (i != 1 && a[i] == 0)
            {
                ok = false;
                break;
            }
            while (a[i] >= a[i + 1])
            {
                ++ans;
                a[i] /= 2;
                if (i != 1 && a[i] == 0)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}