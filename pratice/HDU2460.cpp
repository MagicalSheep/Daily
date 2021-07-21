#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 10;

int N, M;
int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], isbridge[MAXN], dfncnt, bricnt, dep[MAXN];
int fa[MAXN];

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

void tarjan(int u, int p)
{
    dep[u] = dep[p] + 1;
    fa[u] = p;
    dfn[u] = low[u] = ++dfncnt;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                isbridge[v] = 1;
                ++bricnt;
            }
        }
        else if (dfn[v] < dfn[u] && v != p)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(head, 0, sizeof(head));
    memset(dep, 0, sizeof(dep));
    memset(fa, 0, sizeof(fa));
    memset(isbridge, 0, sizeof(isbridge));
    cnt = dfncnt = bricnt = 0;
}

int main()
{
    int T = 0;
    while (1)
    {
        scanf("%d%d", &N, &M);
        if (N == 0 && M == 0)
            break;
        init();
        int A, B;
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &A, &B);
            addEdge(A, B), addEdge(B, A);
        }
        tarjan(1, 0);
        int Q;
        scanf("%d", &Q);
        printf("Case %d:\n", ++T);
        while (Q--)
        {
            scanf("%d%d", &A, &B);
            if (dep[A] < dep[B])
                swap(A, B);
            while (dep[A] != dep[B])
            {
                if (isbridge[A])
                    --bricnt, isbridge[A] = 0;
                A = fa[A];
            }
            while (A != B)
            {
                if (isbridge[A])
                    --bricnt, isbridge[A] = 0;
                if (isbridge[B])
                    --bricnt, isbridge[B] = 0;
                A = fa[A], B = fa[B];
            }
            printf("%d\n", bricnt);
        }
        printf("\n");
    }
    return 0;
}