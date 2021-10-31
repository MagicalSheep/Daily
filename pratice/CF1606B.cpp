#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n, k;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        ll ans = 0;
        ll tmp1 = (ll)ceil(log2((long double)n));
        ll tmp2 = (ll)floor(log2((long double)k));
        if (k >= (1LL << (tmp1 - 1)))
        {
            ans = tmp1;
        }
        else
        {
            ans = tmp2 + 1;
            ll tmp3 = n - (1LL << (tmp2 + 1));
            ans += (ll)ceil((long double)tmp3 / k);
        }
        printf("%lld\n", ans);
    }
    return 0;
}