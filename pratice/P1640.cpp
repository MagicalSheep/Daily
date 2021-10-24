#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int N, match[MAXN];
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
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
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
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, i), addEdge(b, i);
    }
    int ans = 0;
    for (int i = 1; i <= 10000; i++)
    {
        vis.reset();
        if (dfs(i))
            ++ans;
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}