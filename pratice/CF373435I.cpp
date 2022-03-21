#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

int s, n;
pair<ll, ll> ha[MAXN];
ll f[205];

void solve()
{
    for (int i = 0; i <= n; i++)
        f[i] = -0x7fffffff;
    ll ans = -0x7fffffff;
    for (int i = 1; i <= s; i++)
    {
        for (int j = n; j >= 2; j--)
            f[j] = max(f[j], f[j - 1] + ha[i].second);
        f[1] = max(f[1], ha[i].first + ha[i].second);
        ans = max(ans, f[n] - ha[i].first);
    }
    printf("%lld\n", ans);
}

int main()
{
    scanf("%d%d", &s, &n);
    for (int i = 1; i <= s; i++)
        scanf("%lld%lld", &ha[i].second, &ha[i].first);
    sort(ha + 1, ha + 1 + s);
    solve();
    return 0;
}