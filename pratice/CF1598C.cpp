#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN];
map<ll, ll> ma;

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ma.clear();
        scanf("%lld", &n);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), sum += a[i];
        if ((sum << 1) % n != 0)
        {
            printf("0\n");
            continue;
        }
        ll v = (sum << 1) / n, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ma.find(v - a[i]) == ma.end())
                ma.insert(pair<ll, ll>(v - a[i], 0));
            else
                ans += ma[v - a[i]];
            if (ma.find(a[i]) == ma.end())
                ma.insert(pair<ll, ll>(a[i], 1));
            else
                (ma.find(a[i])->second)++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}