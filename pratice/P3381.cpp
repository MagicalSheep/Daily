#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 5e3 + 10;

struct Dinic
{
    struct Edge
    {
        int from, to, cap, flow, cost;
        Edge(int u, int v, int c, int f, int co) : from(u), to(v), cap(c), flow(f), cost(co) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int cur[MAXN], dis[MAXN];
    bool vis[MAXN];

    Dinic(int n)
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool spfa()
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        dis[s] = 0;
        vis[s] = 1;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            vis[x] = 0;
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (e.cap > e.flow && dis[e.to] > dis[e.from] + e.cost)
                {
                    dis[e.to] = dis[e.from] + e.cost;
                    if (!vis[e.to])
                        vis[e.to] = 1, Q.push(e.to);
                }
            }
        }
        return dis[t] != INF;
    }

    pair<ll, ll> DFS(int x, int a)
    {
        if (x == t || a == 0)
            return pair<ll, ll>(a, 0);
        ll flow = 0, cost = 0;
        pair<ll, ll> tmp;
        vis[x] = 1;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edges[G[x][i]];
            if (!vis[e.to] && dis[e.to] == dis[e.from] + e.cost && (tmp = DFS(e.to, min(a, e.cap - e.flow))).first > 0)
            {
                e.flow += tmp.first;
                edges[G[x][i] ^ 1].flow -= tmp.first;
                flow += 1ll * tmp.first;
                cost += 1ll * tmp.first * e.cost + tmp.second;
                a -= tmp.first;
                if (a == 0)
                    break;
            }
        }
        vis[x] = 0;
        return pair<ll, ll>(flow, cost);
    }

    pair<ll, ll> maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flow = 0, cost = 0;
        while (spfa())
        {
            memset(cur, 0, sizeof(cur));
            pair<ll, ll> tmp = DFS(s, INF);
            flow += tmp.first;
            cost += tmp.second;
        }
        return pair<ll, ll>(flow, cost);
    }
};

int n, m, s, t;

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    Dinic dinic(n);
    while (m--)
    {
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        dinic.addEdge(u, v, w, c);
    }
    pair<ll, ll> ans = dinic.maxflow(s, t);
    printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}