#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
const int MAXN = 1e4 + 10;

int N, M, lock1[MAXN], lock2[MAXN];
int cnt, head[MAXN], cphead[MAXN], cpcnt;
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], top, dfncnt, sc;

struct edge
{
    int to, next;
} Edge[MAXN * MAXN];

void init()
{
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(insta, 0, sizeof(insta));
    memset(cphead, -1, sizeof(cphead));
    cpcnt = top = cnt = sc = dfncnt = 0;
}

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
    for (int e = head[u]; e >= 0; e = Edge[e].next)
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

void add(int mid)
{
    for (int i = 1; i <= mid; i++)
    {
        addEdge(lock1[i] + 2 * N, lock2[i]);
        addEdge(lock2[i] + 2 * N, lock1[i]);
    }
}

bool solve()
{
    for (int i = 0; i <= 4 * N - 1; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 0; i <= 2 * N - 1; i++)
        if (belong[i] == belong[i + 2 * N])
            return false;
    return true;
}

void clean()
{
    memset(dfn, 0, sizeof(dfn));
    memset(insta, 0, sizeof(insta));
    cnt = cpcnt;
    memcpy(head, cphead, sizeof(head));
    dfncnt = top = sc = 0;
}

int main()
{
    while (scanf("%d%d", &N, &M) != EOF)
    {
        if (N == 0 && M == 0)
            break;
        init();
        for (int i = 1; i <= N; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            addEdge(a, b + 2 * N);
            addEdge(b, a + 2 * N);
        }
        for (int i = 1; i <= M; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            lock1[i] = a, lock2[i] = b;
        }
        memcpy(cphead, head, sizeof(head));
        cpcnt = cnt;
        int l = 1, r = M, ans = -0x3f3f3f3f;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            add(mid);
            if (solve())
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            clean();
        }
        printf("%d\n", ans);
    }
    return 0;
}