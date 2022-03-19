#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

int t, n, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int mx = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), mx = max(mx, a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]), mx = max(mx, b[i]);
        int tmp = 0;
        for (int i = 1; i <= n; i++)
            tmp = max(tmp, min(a[i], b[i]));
        printf("%d\n", tmp * mx);
    }
    return 0;
}