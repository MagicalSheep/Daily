#include <cstdio>
#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;
const int MAXN = 100 + 10;

int cnt, head[MAXN];
int dfn[MAXN], low[MAXN], dfncnt, cut[MAXN];

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

void tarjan(int u, int rt)
{
    dfn[u] = low[u] = ++dfncnt;
    int child = 0;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (!dfn[v])
        {
            tarjan(v, rt);
            low[u] = min(low[u], low[v]);
            if (rt != u && low[v] >= dfn[u])
                cut[u] = 1;
            if (rt == u)
                child++;
        }
        low[u] = min(low[u], dfn[v]);
    }
    if (rt == u && child >= 2)
        cut[u] = 1;
}

void init()
{
    memset(head, 0, sizeof(head));
    memset(Edge, 0, sizeof(Edge));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(cut, 0, sizeof(cut));
    cnt = dfncnt = 0;
}

int N;

int main()
{
    while (1)
    {
        init();
        cin >> N;
        getchar();
        if (N == 0)
            break;
        string str;
        while (1)
        {
            vector<int> nums;
            getline(cin, str);
            if (str[0] == '0')
                break;
            char *s = (char *)str.c_str();
            char *p = strtok(s, " ");
            int tmp;
            while (p)
            {
                tmp = atoi(p);
                nums.push_back(tmp);
                p = strtok(NULL, " ");
            }
            for (int i = 1; i < nums.size(); i++)
                addEdge(nums[0], nums[i]), addEdge(nums[i], nums[0]);
        }
        for (int i = 1; i <= N; i++)
            if (!dfn[i])
                tarjan(i, i);
        int tot = 0;
        for (int i = 1; i <= N; i++)
            if (cut[i])
                ++tot;
        cout << tot << endl;
    }
    return 0;
}