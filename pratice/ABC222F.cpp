#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 4e5 + 10;

ll N, s_dis[MAXN], t_dis[MAXN];
ll cnt, head[MAXN];
bitset<MAXN> vis;

struct edge
{
    ll to, next, val;
} Edge[MAXN << 1];

void addEdge(ll u, ll v, ll val)
{
    Edge[++cnt].to = v;
    Edge[cnt].val = val;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

ll dfs(ll u, ll p, ll &s)
{
    s = u;
    ll dis = 0;
    for (ll e = head[u]; e; e = Edge[e].next)
    {
        ll v = Edge[e].to;
        ll val = Edge[e].val;
        if (v == p)
            continue;
        ll po;
        ll d = dfs(v, u, po);
        if (d + val > dis)
            s = po, dis = d + val;
    }
    return dis;
}

void dijkstra(ll u, ll *dis)
{
    vis.reset();
    dis[u] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push(pair<ll, ll>(0, u));
    while (q.size())
    {
        auto tmp = q.top();
        q.pop();
        if (vis.test(tmp.second))
            continue;
        vis.set(tmp.second, true);
        for (int e = head[tmp.second]; e; e = Edge[e].next)
        {
            int v = Edge[e].to;
            int val = Edge[e].val;
            if (vis.test(v))
                continue;
            dis[v] = min(dis[v], dis[tmp.second] + val);
            q.push(pair<ll, ll>(dis[v], v));
        }
    }
}

int main()
{
    memset(s_dis, 0x3f, sizeof(s_dis));
    memset(t_dis, 0x3f, sizeof(t_dis));
    scanf("%lld", &N);
    for (ll i = 1; i < N; i++)
    {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    for (ll i = 1; i <= N; i++)
    {
        ll d;
        scanf("%lld", &d);
        addEdge(i, i + N, d);
        addEdge(i + N, i, d);
    }
    ll s, t;
    dfs(1, 1, s);
    dfs(s, s, t);
    dijkstra(s, s_dis);
    dijkstra(t, t_dis);
    for (int i = 1; i <= N; i++)
    {
        if (i == (s - N))
            printf("%lld\n", t_dis[i]);
        else if (i == (t - N))
            printf("%lld\n", s_dis[i]);
        else
            printf("%lld\n", max(s_dis[i], t_dis[i]));
    }
    return 0;
}