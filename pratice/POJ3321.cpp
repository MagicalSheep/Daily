#include <cstdio>
#include <string.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int MAXN = 1e5 + 10;

int cnt, head[MAXN];
int st[MAXN], en[MAXN], tot;
int tree[MAXN], vis[MAXN];
int N, M;

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void init()
{
    cnt = tot = 0;
    memset(head, 0, sizeof(head));
    memset(tree, 0, sizeof(tree));
    memset(vis, 0, sizeof(vis));
}

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void add(int k, int v)
{
    vis[k] = (v == 1) ? 1 : 0;
    for (; k <= N; k += lowbit(k))
        tree[k] += v;
}

int getsum(int k)
{
    int ans = 0;
    for (; k >= 1; k -= lowbit(k))
        ans += tree[k];
    return ans;
}

void dfs(int p, int x)
{
    st[x] = ++tot;
    for (int e = head[x]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (v == p)
            continue;
        dfs(x, v);
    }
    en[x] = tot;
}

int main()
{
    while (scanf("%d", &N) != EOF)
    {
        init();
        for (int i = 1; i < N; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v), addEdge(v, u);
        }
        dfs(1, 1);
        for (int i = 1; i <= N; i++)
        {
            add(st[i], 1);
            vis[st[i]] = 1;
        }
        scanf("%d", &M);
        while (M--)
        {
            char o[3];
            int x;
            scanf("%s", o);
            scanf("%d", &x);
            if (o[0] == 'C')
                add(st[x], (vis[st[x]] == 1) ? -1 : 1);
            else
                printf("%d\n", getsum(en[x]) - getsum(st[x] - 1));
        }
    }
    return 0;
}