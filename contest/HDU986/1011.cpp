#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n, ll k)
{
    bool first = true, flag = false;
    if (k == 1)
        return 2 * n - 1;
    if (k >= n)
        return 1;
    ll sum = 1, cut = 0, last = 0;
    while (1)
    {
        int tmp = n;
        if (first && n % 2 != 0)
            first = false, last = n - 1;
        if (n % 2 == 0)
            n /= 2;
        else
            n = (n + 1) / 2;
        if (!first && (last = last / 2) == k)
            flag = true;
        sum *= 2;
        if (n <= k)
            break;
        cut += (tmp % 2 == 0) ? 0 : sum / 2;
    }
    ll ans = sum - cut;
    return (flag) ? 2 * ans - 1 : 2 * sum - 1;
}

int T;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", solve(n, k));
    }
    return 0;
}