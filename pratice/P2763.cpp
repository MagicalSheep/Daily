#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 30;

int nn, k;
vector<int> ans[20 + 5];

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

    void init(int n)
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
            if (x != t && e.from != s)
                ans[x - 1 - nn].emplace_back(e.from - 1);
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

ISAP isap;

int main()
{
    scanf("%d%d", &k, &nn);
    isap.init(2 + k + nn);
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d", &x);
        isap.addEdge(1 + nn + i, 2 + nn + k, x);
    }
    for (int i = 1; i <= nn; i++)
    {
        isap.addEdge(1, 1 + i, 1);
        int p, x;
        scanf("%d", &p);
        while (p--)
        {
            scanf("%d", &x);
            isap.addEdge(1 + i, 1 + nn + x, 1);
        }
    }
    if (isap.maxflow(1, 2 + nn + k) == 0)
    {
        printf("No Solution!\n");
        return 0;
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d: ", i);
        for (auto x : ans[i])
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}