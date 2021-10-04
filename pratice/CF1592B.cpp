#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll t, n, x, a[MAXN], b[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &x);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), b[i] = a[i];
        if (n >= 2 * x)
        {
            printf("YES\n");
            continue;
        }
        sort(b + 1, b + 1 + n);
        bool isok = true;
        for (int i = max(1LL, n - x + 1); i <= min(n, x); i++)
        {
            if (a[i] != b[i])
            {
                isok = false;
                break;
            }
        }
        if (isok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}