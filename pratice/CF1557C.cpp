#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define P 1000000007

ll t, n, k;

ll fpow_mod(ll x, ll n, ll m)
{
    if (n == 0)
        return 1;
    x %= m;
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        if (k == 0)
        {
            printf("1\n");
            continue;
        }
        ll tmp = fpow_mod(2, n - 1, P);
        ll ans = fpow_mod((n & 1) ? tmp + 1 : tmp - 1, k, P);
        if (!(n & 1))
        {
            ll x = fpow_mod(2, n, P);
            for (int i = 1; i <= k; i++)
                ans = (ans + fpow_mod(x, i - 1, P) * fpow_mod(tmp - 1, k - i, P) % P) % P;
        }
        printf("%lld\n", ans);
    }
    return 0;
}