#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e6 + 10;

ll cnt, head[MAXN];
ll dfn[MAXN], low[MAXN], dfncnt, cut[MAXN];

struct edge
{
    ll to, next;
} Edge[MAXN << 1];

void addEdge(ll u, ll v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void tarjan(ll u, ll rt)
{
    dfn[u] = low[u] = ++dfncnt;
    ll child = 0;
    for (ll e = head[u]; e; e = Edge[e].next)
    {
        ll v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v, rt);
            low[u] = min(low[u], low[v]);
            if (rt != u && low[v] >= dfn[u])
                cut[u] = 1;
            if (rt == u)
                child++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if (rt == u && child >= 2)
        cut[u] = 1;
}

ll n, m;

int main()
{
    scanf("%lld%lld", &n, &m);
    while (m--)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        addEdge(x, y), addEdge(y, x);
    }
    for (ll i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    ll tot = 0;
    for (ll i = 1; i <= n; i++)
        if (cut[i])
            ++tot;
    printf("%lld\n", tot);
    for (ll i = 1; i <= n; i++)
        if (cut[i])
            printf("%lld ", i);
    return 0;
}