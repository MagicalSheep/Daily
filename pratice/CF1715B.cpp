#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;
ll n, k, b, s;

void solve()
{
    if (s / k == b)
    {
        for (int i = 1; i < n; i++)
            printf("0 ");
        printf("%lld\n", s);
        return;
    }
    if (s / k < b)
    {
        printf("-1\n");
        return;
    }
    ll u = (k - 1) * (n - 1);
    ll tmp = k * (b + 1) - 1;
    ll r = s - tmp;
    if (r > u)
    {
        printf("-1\n");
        return;
    }
    printf("%lld ", tmp);
    for (int i = n - 1; i >= 1; i--)
    {
        if (r >= k - 1)
        {
            printf("%lld ", k - 1);
            r -= (k - 1);
        }
        else
        {
            printf("%lld ", r);
            r = 0;
        }
    }
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &n, &k, &b, &s);
        solve();
    }
    return 0;
}