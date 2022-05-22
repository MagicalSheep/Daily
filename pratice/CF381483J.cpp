#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        ll sum = 0, mx = 0;
        for (int i = 1; i <= n; i++)
        {
            ll in;
            scanf("%lld", &in);
            sum += in;
            mx = max(mx, in);
        }
        if (sum & 1)
        {
            printf("NO\n");
            continue;
        }
        if ((sum - mx) < mx)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}