#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int t, n, m, fn, color[MAXN];
int cnt, head[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN << 2];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

bool dfs(int u, int c, int &r, int &b)
{
    color[u] = c;
    if (u <= n)
    {
        if (c == 1)
            ++r;
        else
            ++b;
    }
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (color[v] == c)
            return false;
        if (color[v] == 0 && !dfs(v, -c, r, b))
            return false;
    }
    return true;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(color, 0, sizeof(color));
        scanf("%d%d", &n, &m);
        fn = n;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            char c[10];
            scanf("%d%d%s", &x, &y, c);
            if (strcmp(c, "imposter") == 0)
                addEdge(x, y), addEdge(y, x);
            else
                addEdge(x, ++fn), addEdge(fn, y), addEdge(y, fn), addEdge(fn, x);
        }
        int r, b, ans = 0;
        bool isok = true;
        for (int i = 1; i <= n; i++)
        {
            r = 0, b = 0;
            if (color[i] == 0 && !dfs(i, 1, r, b))
                isok = false;
            ans += max(r, b);
        }
        if (!isok)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}