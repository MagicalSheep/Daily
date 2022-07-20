#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;

ll t, n, m;

ll getinv(ll x)
{
    ll ans = 1, n = MOD - 2;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % MOD;
        n = n / 2;
        x = (x * x) % MOD;
    }
    return (ans + MOD) % MOD;
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        ll ans = ((n - m) * getinv(2)) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}