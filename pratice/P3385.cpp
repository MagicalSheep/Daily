#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;

struct edge
{
    int v, w;
};

int t, n, m, dis[MAXN], vis[MAXN], cnt[MAXN];
vector<edge> Edge[MAXN];

bool bellmanford(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        flag = false;
        for (int u = 1; u <= n; u++)
        {
            for (auto ed : Edge[u])
            {
                int v = ed.v, w = ed.w;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
    }
    return flag;
}

bool spfa(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0, vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (auto ed : Edge[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)
                    return false;
                if (!vis[v])
                    q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (w >= 0)
            {
                Edge[u].emplace_back(edge{v, w});
                Edge[v].emplace_back(edge{u, w});
            }
            else
            {
                Edge[u].emplace_back(edge{v, w});
            }
        }
        if (!spfa(1))
            printf("YES\n");
        else
            printf("NO\n");
        for (int i = 1; i <= n; i++)
            Edge[i].clear();
    }
    return 0;
}