#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int l, r, a;
        scanf("%d%d%d", &l, &r, &a);
        int ans = r / a + r % a, tmp = r - 1;
        if (tmp >= l && tmp <= r)
            ans = max(ans, tmp / a + tmp % a);
        tmp = (r / a - 1) * a + (a - 1);
        if (tmp >= l && tmp <= r)
            ans = max(ans, tmp / a + tmp % a);
        printf("%d\n", ans);
    }
    return 0;
}