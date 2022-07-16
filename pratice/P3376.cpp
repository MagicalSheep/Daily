#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 200 + 5;

struct EK
{
    struct Edge
    {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };

    int n, m;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int a[MAXN], p[MAXN];

    EK(int n)
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    ll maxflow(int s, int t)
    {
        ll flow = 0;
        for (;;)
        {
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while (!Q.empty())
            {
                int x = Q.front();
                Q.pop();
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge &e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t])
                    break;
            }
            if (!a[t])
                break;
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += (1ll * a[t]);
        }
        return flow;
    }
};

struct Dinic
{
    struct Edge
    {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int d[MAXN], cur[MAXN];
    bool vis[MAXN];

    Dinic(int n)
    {
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    ll DFS(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        ll flow = 0, f;
        for (int &i = cur[x]; i < G[x].size(); i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
            {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }

    ll maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

struct ISAP
{
    struct Edge
    {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
    };

    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN], cur[MAXN], p[MAXN], num[MAXN];

    ISAP(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            d[i] = n;
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow)
                {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    int augment()
    {
        int x = t, a = INF;
        while (x != s)
        {
            Edge &e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s)
        {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }

    ll maxflow(int s, int t)
    {
        this->s = s;
        this->t = t;
        ll flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for (int i = 1; i <= n; i++)
            num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while (d[s] < n)
        {
            if (x == t)
            {
                flow += (1ll * augment());
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < G[x].size(); i++)
            {
                Edge &e = edges[G[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1)
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if (!ok)
            {
                int m = n - 1;
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge &e = edges[G[x][i]];
                    if (e.cap > e.flow)
                        m = min(m, d[e.to]);
                }
                if (--num[d[x]] == 0)
                    break;
                num[d[x] = m + 1]++;
                cur[x] = 0;
                if (x != s)
                    x = edges[p[x]].from;
            }
        }
        return flow;
    }
};

int n, m, s, t;

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    // EK ek(n);
    // Dinic dinic(n);
    ISAP isap(n);
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        // ek.addEdge(u, v, w);
        // dinic.addEdge(u, v, w);
        isap.addEdge(u, v, w);
    }
    // printf("%lld\n", ek.maxflow(s, t));
    // printf("%lld\n", dinic.maxflow(s, t));
    printf("%lld\n", isap.maxflow(s, t));
    return 0;
}