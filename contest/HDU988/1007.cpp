#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
    int t;
    ll n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        ll minc = 0, maxc = 0;
        ll temp = ((n % mod) * ((n + 1) % mod)) % mod;
        ll dc = (temp * 500000004) % mod;
        ll pfh = ((((n % mod) * ((n + 1) % mod)) % mod * ((2 * (n % mod) + 1) % mod)) % mod * 166666668) % mod;
        ll fir = ((dc % mod) * (pfh % mod)) % mod;
        minc = ((dc % mod * (pfh % mod)) % mod + (((dc - 1) % mod) * (dc % mod + pfh % mod - 2) % mod) % mod) % mod;
        maxc = (((dc % mod * pfh % mod) % mod * (n % mod)) % mod * (n % mod)) % mod;
        printf("%lld\n%lld\n", minc, maxc);
    }
    return 0;
}