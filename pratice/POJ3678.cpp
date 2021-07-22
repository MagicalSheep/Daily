#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 1e6 + 10;

int N, M;
int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

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

void tarjan(int u)
{
    dfn[u] = low[u] = ++dfncnt;
    sta[++top] = u;
    insta[u] = 1;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (insta[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++sc;
        while (1)
        {
            int v = sta[top--];
            insta[v] = 0;
            belong[v] = sc;
            if (u == v)
                break;
        }
    }
}

bool solve()
{
    for (int i = 0; i < (2 * N); i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i < N; i++)
        if (belong[i] == belong[i + N])
            return false;
    return true;
}

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        for (int i = 1; i <= M; i++)
        {
            int a, b, c;
            char op[20];
            scanf("%d%d%d%s", &a, &b, &c, op);
            if (op[0] == 'A')
            {
                if (c == 1)
                {
                    addEdge(a + N, a); // note: zero must lead to one (force one)
                    addEdge(b + N, b);
                }
                else
                {
                    addEdge(a, b + N);
                    addEdge(b, a + N);
                }
            }
            else if (op[0] == 'O')
            {
                if (c == 1)
                {
                    addEdge(a + N, b);
                    addEdge(b + N, a);
                }
                else
                {
                    addEdge(a, a + N);
                    addEdge(b, b + N);
                }
            }
            else
            {
                if (c == 1)
                {
                    addEdge(a, b + N);
                    addEdge(a + N, b);
                    addEdge(b, a + N);
                    addEdge(b + N, a);
                }
                else
                {
                    addEdge(a, b);
                    addEdge(a + N, b + N);
                    addEdge(b, a);
                    addEdge(b + N, a + N);
                }
            }
        }
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}