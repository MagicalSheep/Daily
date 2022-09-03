#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e8;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll ans = 4ll * (n / 3) + 2ll * (n / 2 - n / 3) + n;
        printf("%lld\n", ans);
    }
    return 0;
}