#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 4e5 + 10;

ll t, n, k, x[MAXN], sum[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        for (int i = 1; i <= k; i++)
            scanf("%lld", &x[i]);
        sort(x + 1, x + 1 + k);
        for (int i = 1; i <= k; i++)
            sum[i] = n - x[i];
        sum[k + 1] = 0;
        for (int i = k; i >= 1; i--)
            sum[i] += sum[i + 1];
        ll ans = 0;
        ll l = 1, r = k, mid = (l + r) >> 1;
        while (l <= r)
        {
            if (sum[mid] < n)
                ans = k - mid + 1, r = mid - 1;
            else
                l = mid + 1;
            mid = (l + r) >> 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}