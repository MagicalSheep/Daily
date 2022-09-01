#include <bits/stdc++.h>
#define id(i, j) (((i - 1) * 30) + j)
#define rev(u) ((u > tot) ? u - tot : u + tot)
using namespace std;
const int MAXN = 6e6 + 1;

int cnt, head[MAXN];

struct edge
{
    int to, next;
} Edge[12000001];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

int n, q, tot, _stack[MAXN], idx;
bool vis[MAXN];

bool dfs(int u)
{
    if (vis[rev(u)])
        return false;
    if (vis[u])
        return true;
    vis[u] = true;
    _stack[++idx] = u;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfs(v))
            return false;
    }
    return true;
}

void solve()
{
    for (int i = 1; i <= 2 * tot; i++)
    {
        if (!vis[i] && !vis[rev(i)])
        {
            idx = 0;
            if (!dfs(i))
            {
                for (int i = 1; i <= idx; i++)
                    vis[_stack[i]] = false;
                dfs(rev(i));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    tot = n * 30;
    while (q--)
    {
        int i, j, x;
        scanf("%d%d%d", &i, &j, &x);
        for (int _i = 1; _i <= 30; _i++)
        {
            if ((x >> (_i - 1)) & 1)
            {
                addEdge(id(i, _i), id(j, _i) + tot);
                addEdge(id(j, _i), id(i, _i) + tot);
            }
            else
            {
                addEdge(id(i, _i) + tot, id(i, _i));
                addEdge(id(j, _i) + tot, id(j, _i));
            }
        }
    }
    solve();
    for (int i = 1; i <= n; i++)
    {
        int a = 0;
        for (int j = 30; j >= 1; j--)
        {
            if (vis[id(i, j) + tot])
                a |= 1;
            a <<= 1;
        }
        a >>= 1;
        printf("%d ", a);
    }
    printf("\n");
    return 0;
}