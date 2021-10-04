#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n, k, x, a[MAXN], val[MAXN];
vector<int> edge[MAXN];

inline void addEdge(int u, int v) { edge[u].emplace_back(v); }

bool dfs(int p, int u)
{
    val[u] = a[u];
    for (auto v : edge[u])
    {
        if (v == p)
            continue;
        if (dfs(u, v))
            return true;
        val[u] ^= val[v];
    }
    if (p != u && val[u] == x)
    {
        edge[p].erase(find(edge[p].begin(), edge[p].end(), u));
        edge[u].erase(find(edge[u].begin(), edge[u].end(), p));
        return true;
    }
    return false;
}

int dfs2(int p, int u)
{
    int ret = a[u];
    for (auto v : edge[u])
    {
        if (v == p)
            continue;
        ret ^= dfs2(u, v);
    }
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        x = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), x ^= a[i];
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v), addEdge(v, u);
        }
        if ((x == 0) || (k > 2 && dfs(1, 1) && dfs(1, 1) && dfs2(1, 1) == x))
            printf("YES\n");
        else
            printf("NO\n");
        for (int i = 1; i <= n; i++)
            edge[i].clear();
    }
    return 0;
}