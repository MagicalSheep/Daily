#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

ll n, c, d[N], k, sum;
vector<ll> E[N];
map<pair<ll, ll>, ll> vals;

void dfs(ll u, ll fa)
{
    for (ll v : E[u])
    {
        if (v == fa)
            continue;
        d[v] = d[u] + vals[pair<ll, ll>(u, v)];
        if (d[v] > d[c])
            c = v;
        dfs(v, u);
    }
}

int main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i < n; i++)
    {
        ll u, v, val;
        scanf("%lld%lld%lld", &u, &v, &val);
        E[u].push_back(v), E[v].push_back(u);
        vals[pair<ll, ll>(u, v)] = vals[pair<ll, ll>(v, u)] = val;
        sum += val;
    }
    if (k >= 2)
    {
        printf("%lld\n", sum);
        return 0;
    }
    dfs(1, 0);
    d[c] = 0, dfs(c, 0);
    printf("%lld\n", d[c]);
    return 0;
}
