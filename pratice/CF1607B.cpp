#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll t, n, x;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &x, &n);
        ll ans = 0;
        if (n == 0)
        {
            printf("%lld\n", x);
            continue;
        }
        if (n % 4 == 0)
        {
            printf("%lld\n", x);
            continue;
        }
        ll remain = n % 4;
        ll tmp = (n / 4) * 4;
        ll n_1 = tmp + 1;
        ll n_2 = tmp + 2;
        ll n_3 = tmp + 3;
        if (x & 1)
        {
            if (remain == 1)
                ans = x + n_1;
            else if (remain == 2)
                ans = x + n_1 - n_2;
            else
                ans = x + n_1 - n_2 - n_3;
        }
        else
        {
            if (remain == 1)
                ans = x - n_1;
            else if (remain == 2)
                ans = x - n_1 + n_2;
            else
                ans = x - n_1 + n_2 + n_3;
        }
        printf("%lld\n", ans);
    }
    return 0;
}