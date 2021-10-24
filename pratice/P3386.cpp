#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 10;

int n, m, e, match[MAXN];
int cnt, head[MAXN];
bitset<MAXN> vis;

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

bool dfs(int u)
{
    for (int i = head[u]; i; i = Edge[i].next)
    {
        int v = Edge[i].to;
        if (vis.test(v))
            continue;
        vis.set(v, true);
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vis.reset();
        if (dfs(i))
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}