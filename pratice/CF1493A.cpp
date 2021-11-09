#include <bits/stdc++.h>
using namespace std;

int T, n, k;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        int ans = 0, tmp = 0;
        if (k & 1)
            ans += (k - 1) / 2;
        else
            ans += k / 2;
        tmp = ans;
        ans += (n - k);
        printf("%d\n", ans);
        for (int i = k - tmp; i <= n; i++)
        {
            if (i == k)
                continue;
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}