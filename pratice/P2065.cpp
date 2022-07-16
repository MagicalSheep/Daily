#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 10;
const int MAXM = 1e7 + 10;

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

    void init(int n)
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

int t, m, n, k, cnt, b[MAXN], r[MAXN], prime[MAXN];
bool np[MAXM];
Dinic dinic;

void init()
{
    np[0] = np[1] = true;
    for (int i = 2; i < MAXM; ++i)
    {
        if (!np[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && 1ll * i * prime[j] < MAXM; ++j)
        {
            np[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void linkb(int id)
{
    int x = b[id];
    for (int j = 1; j <= cnt && prime[j] <= x; j++)
    {
        if (x % prime[j] == 0)
        {
            dinic.addEdge(1 + id, 2 + m + n + j, INF);
            while (x % prime[j] == 0)
                x /= prime[j];
        }
    }
}

void linkr(int id)
{
    int x = r[id];
    for (int j = 1; j <= cnt && prime[j] <= x; j++)
    {
        if (x % prime[j] == 0)
        {
            dinic.addEdge(2 + m + n + j, 1 + m + id, INF);
            while (x % prime[j] == 0)
                x /= prime[j];
        }
    }
}

int main()
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        dinic.init(2 + m + n + cnt);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]), dinic.addEdge(1, 1 + i, 1), linkb(i);
        for (int i = 1; i <= n; i++)
            scanf("%d", &r[i]), dinic.addEdge(1 + m + i, 2 + m + n, 1), linkr(i);
        printf("%lld\n", dinic.maxflow(1, 2 + m + n));
    }
    return 0;
}