#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll t, n, m;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &m);
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        sort(a.begin(), a.end());
        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += (a[i] + 1);
        if (m - sum + a[0] >= a[n - 1])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}