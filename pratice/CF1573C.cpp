#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n;
int cnt, head[MAXN], ind[MAXN];
int f[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN];

inline void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(ind, 0, sizeof(ind));
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            f[i] = 1;
            if (k == 0)
                q.push(i);
            for (int j = 1; j <= k; j++)
            {
                int from;
                scanf("%d", &from);
                addEdge(from, i);
                ++ind[i];
            }
        }
        if (q.empty())
        {
            printf("-1\n");
            continue;
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int e = head[u]; e; e = Edge[e].next)
            {
                int v = Edge[e].to;
                --ind[v];
                if (ind[v] == 0)
                    q.push(v);
                int y;
                if (v < u)
                    y = f[u] + 1;
                else
                    y = f[u];
                f[v] = max(f[v], y);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ind[i] != 0)
            {
                ans = -1;
                break;
            }
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}