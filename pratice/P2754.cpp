#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 3e6 + 10;

/** Disjoint Set Begin **/
namespace DSet
{
    int fa[25];

    void makeSet(int size)
    {
        for (int i = 0; i < size; i++)
            fa[i] = i;
    }

    int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

    void unionSet(int x, int y) { fa[find(x)] = find(y); }
}
/** Disjoint Set End **/

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

int n, m, k, h[25], d, sum;
vector<int> s[25];
Dinic dinic;

int main()
{
    DSet::makeSet(25);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int r, x, last = -2;
        scanf("%d%d", &h[i], &r);
        while (r--)
        {
            scanf("%d", &x);
            s[i].emplace_back(x);
            x = (x == 0) ? (n + 1) : x;
            x = (x == -1) ? (n + 2) : x;
            if (last != -2)
                DSet::unionSet(last, x);
            last = x;
        }
    }
    if (DSet::find(n + 1) != DSet::find(n + 2))
    {
        printf("0\n");
        return 0;
    }
    dinic.addEdge(1, 2 + 1, INF);
    dinic.addEdge(2 + n + 2, 2, INF);
    ++d;
    while (1)
    {
        int st = 2 + (d * (2 + n)) + 1;
        int last_st = 2 + ((d - 1) * (2 + n)) + 1;
        int ed = st + n + 1;
        int last_ed = last_st + n + 1;
        dinic.addEdge(last_st, st, INF);
        dinic.addEdge(last_ed, ed, INF);
        dinic.addEdge(ed, 2, INF);
        for (int i = 1; i <= n; i++)
            dinic.addEdge(last_st + i, st + i, INF);
        for (int i = 1; i <= m; i++)
        {
            int from = s[i][(d - 1) % s[i].size()];
            int to = s[i][d % s[i].size()];
            if (from == -1)
                from = last_ed;
            else
                from += last_st;
            if (to == -1)
                to = ed;
            else
                to += st;
            dinic.addEdge(from, to, h[i]);
        }
        sum += dinic.maxflow(1, 2);
        if (sum >= k)
            break;
        ++d;
    }
    printf("%d\n", d);
    return 0;
}