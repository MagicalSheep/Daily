#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
const int P = 1e9 + 7;

ll t, n, f[MAXN];

int main()
{
    f[1] = 1;
    for (ll i = 2; i <= 100000; i++)
        f[i] = f[i - 1] * (i << 1) % P * ((i << 1) - 1) % P;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", f[n]);
    }
    return 0;
}