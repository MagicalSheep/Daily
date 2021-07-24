#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;

int n, m, k, f[MAXN][MAXN], tt[MAXN], a[MAXN], b[MAXN], c[MAXN];
int cnt, head[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

int main()
{
    memset(f, -0x3f, sizeof(f));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i <= k; i++)
        f[0][i] = 0; // note: init
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    for (int i = 1; i <= n; i++)
        tt[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        tt[v] = max(tt[v], u);
    }
    for (int i = 1; i <= n; i++)
        addEdge(tt[i], i);
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= 5000; j++)
            f[i][j + b[i]] = max(f[i][j + b[i]], f[i - 1][j]);
        for (int e = head[i]; e; e = Edge[e].next)
        {
            int v = Edge[e].to;
            for (int j = 0; j < 5000; j++)
                f[i][j] = max(f[i][j], f[i][j + 1] + c[v]);
        }
    }
    int ans = -1;
    for (int i = 0; i <= 5000; i++)
        ans = max(ans, f[n][i]);
    printf("%d\n", ans);
    return 0;
}