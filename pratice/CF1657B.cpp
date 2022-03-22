#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n, B, x, y;

void solve()
{
    ll ans = 0, last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (last + x <= B)
        {
            last += x;
            ans += last;
        }
        else
        {
            last -= y;
            ans += last;
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &n, &B, &x, &y);
        solve();
    }
    return 0;
}