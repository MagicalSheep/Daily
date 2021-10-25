#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll t, n, a[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n; i += 2)
                printf("%lld %lld ", a[i + 1], -a[i]);
            printf("\n");
        }
        else
        {
            for (int i = 1; i <= n - 3; i += 2)
                printf("%lld %lld ", a[i + 1], -a[i]);
            ll sum = a[n] + a[n - 1] + a[n - 2];
            ll mu, zi, pos;
            for (int i = n - 2; i <= n; i++)
            {
                if (sum - a[i] != 0)
                {
                    mu = sum - a[i];
                    zi = a[i];
                    pos = i;
                    break;
                }
            }
            for (int i = n - 2; i <= n; i++)
                printf("%lld ", (pos == i) ? mu : -zi);
            printf("\n");
        }
    }
    return 0;
}