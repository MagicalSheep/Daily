#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

ll N, T[MAXN], ans;
int cnt, head[MAXN], vis[MAXN];

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

void dfs(int u)
{
    ans += T[u];
    vis[u] = 1;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    scanf("%lld", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &T[i]);
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++)
        {
            int v;
            scanf("%d", &v);
            addEdge(i, v);
        }
    }
    dfs(N);
    printf("%lld\n", ans);
    return 0;
}