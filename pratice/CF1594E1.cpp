#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int P = 1e9 + 7;

ll k;

ll fpow_mod(ll x, ll n, ll m)
{
    if (n == 0)
        return 1;
    x %= m;
    long long ans = 1;
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
    scanf("%lld", &k);
    ll tmp = (1LL << k) - 2;
    ll ans = fpow_mod(4, tmp, P);
    ans = (6 * ans) % P;
    printf("%lld\n", ans);
    return 0;
}