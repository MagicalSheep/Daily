#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int t;

ll solve(ll n, ll m)
{
    if (m == 1)
    {
        if (n == 1)
            return 0;
        else if (n == 2)
            return 1;
        else
            return -1;
    }
    if (n == 1)
    {
        if (m == 1)
            return 0;
        else if (m == 2)
            return 1;
        else
            return -1;
    }
    if (m == 2)
    {
        if (n & 1)
            return 2 * (n - 2) + 1;
        else
            return 2 * (n - 1);
    }
    if (n == m + 1)
        return 2 * m - 1;
    if (n == m)
        return 2 * m - 2;
    ll tmp1 = solve(m - 1, m - 1);
    ll tmp2 = solve(n - m + 2, 2);
    if (tmp1 == -1 || tmp2 == -1)
        return -1;
    return tmp1 + tmp2;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll mx, mn;
        mx = max(n, m);
        mn = min(n, m);
        n = mx, m = mn;
        printf("%lld\n", solve(n, m));
    }
    return 0;
}