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

int n, m, s, t;

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    EK ek(n);
    while (m--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ek.addEdge(u, v, w);
    }
    printf("%lld\n", ek.maxflow(s, t));
    return 0;
}