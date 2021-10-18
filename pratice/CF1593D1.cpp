#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int mn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), mn = min(mn, a[i]);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = __gcd(ans, a[i] - mn);
        printf("%d\n", (ans) ? ans : -1);
    }
    return 0;
}