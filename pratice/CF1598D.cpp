#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll t, n, a[MAXN], b[MAXN];
ll a_cnt[MAXN], b_cnt[MAXN];
vector<ll> diff[MAXN];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%lld", &a[i], &b[i]);
            ++a_cnt[a[i]], ++b_cnt[b[i]];
            diff[a[i]].emplace_back(b[i]);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a_cnt[i] < 2)
                continue;
            ll ccnt = 0;
            for (auto x : diff[i])
                ccnt += max(0LL, b_cnt[x] - 1) * (diff[i].size() - 1);
            ans += ccnt;
        }
        ans = (n * (n - 1) * (n - 2) / 6) - ans;
        printf("%lld\n", ans);
        for (int i = 1; i <= n; i++)
        {
            a_cnt[i] = 0, b_cnt[i] = 0;
            diff[i].clear();
        }
    }
    return 0;
}