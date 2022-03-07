#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll mx = 0, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            ll in;
            scanf("%lld", &in);
            sum += in;
            mx = max(mx, in);
        }
        if (mx == 0)
        {
            printf("0\n");
            continue;
        }
        sum -= mx;
        printf("%lld\n", (mx <= sum) ? 1 : mx - sum);
    }
    return 0;
}