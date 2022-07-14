#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll n, cnt, uf, vf, flag[MAXN], disrt[MAXN], disu[MAXN], disv[MAXN], fr[MAXN];
ll sum;
vector<ll> tr[MAXN], leaf;

struct node
{
    ll a, b, c;
} ans[MAXN];

void dfs1(ll u, ll fa)
{
    disrt[u] = disrt[fa] + 1;
    if (disrt[u] > disrt[uf])
        uf = u;
    for (auto v : tr[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
    }
}

void dfs2(ll u, ll fa)
{
    fr[u] = fa;
    disu[u] = disu[fa] + 1;
    if (disu[u] > disu[vf])
        vf = u;
    for (auto v : tr[u])
    {
        if (v == fa)
            continue;
        dfs2(v, u);
    }
    leaf.emplace_back(u);
}

void dfs3(ll u, ll fa)
{
    disv[u] = disv[fa] + 1;
    for (auto v : tr[u])
    {
        if (v == fa)
            continue;
        dfs3(v, u);
    }
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        tr[a].emplace_back(b);
        tr[b].emplace_back(a);
    }
    disrt[0] = disu[0] = disv[0] = -1;
    dfs1(1, 0);
    dfs2(uf, 0);
    dfs3(vf, 0);
    for (ll i = vf; i != uf; i = fr[i])
        flag[i] = 1;
    flag[uf] = 1;
    for (auto i : leaf)
    {
        if (flag[i])
            continue;
        ll tmp = (disu[i] > disv[i]) ? uf : vf;
        sum += max(disu[i], disv[i]);
        ans[cnt++] = {i, tmp, i};
    }
    for (ll i = vf; i != uf; i = fr[i])
    {
        sum += disu[i];
        ans[cnt++] = {i, uf, i};
    }
    printf("%lld\n", sum);
    for (ll i = 0; i < cnt; i++)
        printf("%lld %lld %lld\n", ans[i].a, ans[i].b, ans[i].c);
    return 0;
}