#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;

ll n, b[MAXN], c[MAXN], ans[MAXN];
map<ll, bool> isok;
map<ll, ll> pid;
set<ll> node;

void prework()
{
    ll ind = 1, last_pos = 0;
    for (auto pos : node)
    {
        if (isok[pos])
            ans[ind] = ans[ind - 1] + pos - last_pos;
        else
            ans[ind] = ans[ind - 1] + 3 * (pos - last_pos);
        pid[pos] = ind;
        last_pos = pos;
        ind++;
    }
}

ll solve(ll ed)
{
    ll ret = 2 * (max(c[n], b[n]) - ed);
    ret += ans[pid[ed]];
    return ret;
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &b[i]), node.insert(b[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &c[i]), node.insert(c[i]);
    ll last_pos = 0;
    for (auto pos : node)
    {
        ll kcnt = upper_bound(c + 1, c + 1 + n, last_pos) - c - 1;
        ll bcnt = upper_bound(b + 1, b + 1 + n, last_pos) - b - 1;
        if (kcnt >= bcnt)
            isok[pos] = true;
        else
            isok[pos] = false;
        last_pos = pos;
    }
    prework();
    ll ans = 0x7fffffff;
    for (auto pos : node)
        ans = min(ans, solve(pos));
    printf("%lld\n", ans);
    return 0;
}