#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define P 1000000007

ll t;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        n %= P;
        ll ans = (n - 1) * n % P * (n - 1) % P * n % P * 2 % P;
        printf("%lld\n", ans);
    }
    return 0;
}