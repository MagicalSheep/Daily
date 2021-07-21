#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 100 + 10;

int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], sta[MAXN], insta[MAXN], belong[MAXN], dfncnt, top, sc;
int ind[MAXN], outd[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN * MAXN];

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
            belong[v] = sc;
            insta[v] = 0;
            if (u == v)
                break;
        }
    }
}

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int v;
        while (1)
        {
            cin >> v;
            if (v == 0)
                break;
            addEdge(i, v);
        }
    }
    for (int i = 1; i <= N; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= N; i++)
    {
        for (int e = head[i]; e; e = Edge[e].next)
        {
            int v = Edge[e].to;
            if (belong[i] == belong[v])
                continue;
            ind[belong[v]]++;
            outd[belong[i]]++;
        }
    }
    int in = 0, out = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (ind[i] == 0)
            in++;
        if (outd[i] == 0)
            out++;
    }
    cout << in << endl;
    if (sc == 1)
        cout << 0 << endl;
    else
        cout << max(in, out) << endl;
    return 0;
}