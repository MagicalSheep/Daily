#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18 + 5;
const int MAXN = 1e5 + 10;

struct node
{
    int l, r, id;
} tree1[MAXN << 2], tree2[MAXN << 2];

int tot, cnt, head[MAXN << 3], leaf1[MAXN << 3], leaf2[MAXN << 3]; // note: do not forget the head array length

struct edge
{
    int to, next;
    ll val;
};

vector<edge> Edge;

void addEdge(int u, int v, ll val)
{
    edge e;
    e.to = v;
    e.val = val;
    e.next = head[u];
    Edge.emplace_back(e);
    head[u] = ++cnt;
}

void build_up(int p, int s, int t)
{
    tree1[p].l = s;
    tree1[p].r = t;
    tree1[p].id = ++tot;
    if (s == t)
    {
        leaf1[s] = tree1[p].id;
        return;
    }
    int mid = (s + t) >> 1;
    build_up(p << 1, s, mid), build_up(p << 1 | 1, mid + 1, t);
    addEdge(tree1[p << 1].id, tree1[p].id, 0);
    addEdge(tree1[p << 1 | 1].id, tree1[p].id, 0);
}

void build_down(int p, int s, int t)
{
    tree2[p].l = s;
    tree2[p].r = t;
    tree2[p].id = ++tot;
    if (s == t)
    {
        leaf2[s] = tree2[p].id;
        return;
    }
    int mid = (s + t) >> 1;
    build_down(p << 1, s, mid), build_down(p << 1 | 1, mid + 1, t);
    addEdge(tree2[p].id, tree2[p << 1].id, 0);
    addEdge(tree2[p].id, tree2[p << 1 | 1].id, 0);
}

void build_map(int n)
{
    edge e;
    Edge.emplace_back(e);
    build_up(1, 1, n);
    build_down(1, 1, n);
    for (int i = 1; i <= n; i++)
        addEdge(leaf2[i], leaf1[i], 0);
}

void add_section_to_dot(int p, int l, int r, int v, ll val)
{
    if (tree1[p].l >= l && tree1[p].r <= r)
    {
        addEdge(tree1[p].id, leaf1[v], val);
        return;
    }
    int mid = (tree1[p].l + tree1[p].r) >> 1;
    if (l <= mid)
        add_section_to_dot(p << 1, l, r, v, val);
    if (r > mid)
        add_section_to_dot(p << 1 | 1, l, r, v, val);
}

void add_dot_to_section(int p, int u, int l, int r, ll val)
{
    if (tree2[p].l >= l && tree2[p].r <= r)
    {
        addEdge(leaf1[u], tree2[p].id, val);
        return;
    }
    int mid = (tree2[p].l + tree2[p].r) >> 1;
    if (l <= mid)
        add_dot_to_section(p << 1, u, l, r, val);
    if (r > mid)
        add_dot_to_section(p << 1 | 1, u, l, r, val);
}

bool vis[MAXN << 3];
ll dis[MAXN << 3];

void dijkstra(ll start)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < (MAXN << 3); i++)
        dis[i] = INF;
    dis[start] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, start});
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int e = head[u]; e; e = Edge[e].next)
        {
            if (vis[Edge[e].to])
                continue;
            dis[Edge[e].to] = min(dis[Edge[e].to], dis[u] + Edge[e].val);
            q.push({dis[Edge[e].to], Edge[e].to});
        }
    }
}

int n, q, s;

int main()
{
    cin >> n >> q >> s;
    build_map(n);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, u;
            ll w;
            cin >> v >> u >> w;
            addEdge(leaf1[v], leaf2[u], w);
        }
        else
        {
            int v, l, r;
            ll w;
            cin >> v >> l >> r >> w;
            if (t == 2)
                add_dot_to_section(1, v, l, r, w);
            else
                add_section_to_dot(1, l, r, v, w);
        }
    }
    dijkstra(leaf1[s]);
    for (int i = 1; i <= n; i++)
    {
        if (dis[leaf1[i]] != INF)
            cout << dis[leaf1[i]] << " ";
        else
            cout << "-1 ";
    }
    cout << endl;
    return 0;
}