#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int P = 1e9 + 7;

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
        ll ans = 0, po = 0;
        while (k)
        {
            if (k & 1)
                ans = (ans + fpow_mod(n, po, P)) % P;
            ++po;
            k >>= 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}