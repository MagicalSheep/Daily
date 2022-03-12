#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN], b[MAXN];

ll best(ll val, ll *arr)
{
    ll ret = 0x7fffffff;
    for (int i = 1; i <= n; i++)
        ret = min(ret, abs(val - arr[i]));
    return ret;
}

void solve()
{
    ll ans = 0x7fffffff;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            ll sum = 0;
            bool flag1 = false, flag2 = false;
            if (i == 1)
            {
                sum += abs(a[1] - b[1]);
                flag1 = true;
            }
            else if (i == 2)
            {
                sum += abs(a[1] - b[n]);
                flag2 = true;
            }
            else
            {
                ll tmp = best(a[1], b);
                sum += tmp;
                if (tmp == abs(a[1] - b[1]))
                    flag1 = true;
                else if (tmp == abs(a[1] - b[n]))
                    flag2 = true;
            }
            if (j == 1)
            {
                sum += abs(a[n] - b[1]);
                flag1 = true;
            }
            else if (j == 2)
            {
                sum += abs(a[n] - b[n]);
                flag2 = true;
            }
            else
            {
                ll tmp = best(a[n], b);
                sum += tmp;
                if (tmp == abs(a[n] - b[1]))
                    flag1 = true;
                else if (tmp == abs(a[n] - b[n]))
                    flag2 = true;
            }
            if (!flag1)
                sum += best(b[1], a);
            if (!flag2)
                sum += best(b[n], a);
            ans = min(ans, sum);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &b[i]);
        solve();
    }
    return 0;
}