#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 10;

int t, n, a[MAXN], x;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%d", &x);
        for (int i = 1; i <= n; i++)
            a[i] -= x;
        int sum = a[1], cnt = 0;
        for (int l = 1, r = 2; l <= n && r <= n; ++r)
        {
            sum += a[r];
            if (sum < 0)
            {
            repeat:
                ++cnt;
                l = r = r + 1;
                sum = a[l];
                continue;
            }
            if (r - l + 1 >= 3)
            {
                sum -= a[l];
                ++l;
                if (sum < 0)
                    goto repeat;
            }
        }
        printf("%d\n", n - cnt);
    }
    return 0;
}