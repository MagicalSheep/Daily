#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int t, n, a[MAXN], pos[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(pos, 0, sizeof(pos));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            if (pos[a[i]] == 0)
            {
                pos[a[i]] = i;
                continue;
            }
            int delta = i - pos[a[i]];
            pos[a[i]] = i;
            mn = min(mn, delta);
        }
        if (mn == 0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", n - mn);
    }
    return 0;
}