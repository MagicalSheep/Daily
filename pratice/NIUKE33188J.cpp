#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

int n;

struct point
{
    int id, from, to;
};

struct edge
{
    int v, w;
};

struct node
{
    int dis, u;
    bool operator>(const node &a) const { return dis > a.dis; }
};

struct nnode
{
    int from, mid, to;
    bool operator<(const nnode &x) const
    {
        if (from != x.from)
            return from < x.from;
        if (mid != x.mid)
            return mid < x.mid;
        return to < x.to;
    }
};

vector<point> vec;
vector<int> vvec[MAXN];
vector<edge> g[MAXN << 2];
set<nnode> fl;
int s1, s2, t1, t2, cnt, st, ed;
int dis[MAXN << 2], vis[MAXN << 2];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int n, int s)
{
    memset(dis, 63, sizeof(dis));
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto ed : g[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int c1, c2, c3, c4;
        scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
        fl.insert(nnode{c1, i, c2});
        fl.insert(nnode{c2, i, c3});
        fl.insert(nnode{c3, i, c4});
        fl.insert(nnode{c4, i, c1});
        if (c1 != 0)
        {
            vvec[i].emplace_back(cnt);
            vec.emplace_back(point{cnt++, i, c1});
        }
        if (c2 != 0)
        {
            vvec[i].emplace_back(cnt);
            vec.emplace_back(point{cnt++, i, c2});
        }
        if (c3 != 0)
        {
            vvec[i].emplace_back(cnt);
            vec.emplace_back(point{cnt++, i, c3});
        }
        if (c4 != 0)
        {
            vvec[i].emplace_back(cnt);
            vec.emplace_back(point{cnt++, i, c4});
        }
    }
    scanf("%d%d%d%d", &s1, &s2, &t1, &t2);
    for (auto p : vec)
    {
        if (p.from == s1 && p.to == s2)
            st = p.id + 1;
        else if (p.from == t1 && p.to == t2)
            ed = p.id + 1;
        for (auto v : vvec[p.to])
        {
            point e = vec[v];
            if (fl.count(nnode{p.from, p.to, e.to}))
                g[p.id + 1].emplace_back(edge{e.id + 1, 0});
            else
                g[p.id + 1].emplace_back(edge{e.id + 1, 1});
        }
    }
    dijkstra(cnt, st);
    if (dis[ed] == 0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", dis[ed]);
    return 0;
}