#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int V, N;
int head[MAXN], cnt;
int mx;

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

void dfs(int u, int p, int dep)
{
    mx = max(mx, dep);
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (v == p)
            continue;
        dfs(v, u, dep + 1);
    }
}

int main()
{
    scanf("%d%d", &V, &N);
    for (int i = 1; i < V; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        ++a, ++b;
        addEdge(a, b), addEdge(b, a);
    }
    dfs(1, 1, 1);
    if (N < mx)
        printf("%d\n", N + 1);
    else
        printf("%d\n", min(V, mx + (N - mx + 1) / 2));
    return 0;
}