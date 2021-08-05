#include <bits/stdc++.h>
typedef long long ll;
#define P 998244353
using namespace std;

int T;

ll fpow_mod(ll a, ll b, ll m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        ll po = fpow_mod(2, (k & 1) ? (k - 1) >> 1 : k >> 1, P);
        ll ans1 = (k & 1) ? (po * a % P + po * b % P) % P : po * a % P;
        ll ans2 = (k & 1) ? (po * a % P - po * b % P + P) % P : po * b % P;
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}