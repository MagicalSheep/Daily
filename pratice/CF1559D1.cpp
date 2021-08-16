#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;

int n, m1, m2;
int fa1[MAXN], fa2[MAXN];
int mem1[MAXN][MAXN], mem2[MAXN][MAXN];

int Find1(int x)
{
    if (x != fa1[x])
        fa1[x] = Find1(fa1[x]);
    return fa1[x];
}

void unionSet1(int x, int y)
{
    x = Find1(x);
    y = Find1(y);
    fa1[x] = y;
}

int Find2(int x)
{
    if (x != fa2[x])
        fa2[x] = Find2(fa2[x]);
    return fa2[x];
}

void unionSet2(int x, int y)
{
    x = Find2(x);
    y = Find2(y);
    fa2[x] = y;
}

int main()
{
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++)
        fa1[i] = i, fa2[i] = i;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        unionSet1(u, v);
        mem1[u][v] = 1;
    }
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        unionSet2(u, v);
        mem2[u][v] = 1;
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (mem1[i][j])
                continue;
            if (Find1(i) == Find1(j))
            {
                mem1[i][j] = 1;
                continue;
            }
            if (mem2[i][j])
                continue;
            if (Find2(i) == Find2(j))
            {
                mem2[i][j] = 1;
                continue;
            }
            ans.emplace_back(pair<int, int>(i, j));
            unionSet1(i, j);
            unionSet2(i, j);
        }
    }
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d %d\n", x.first, x.second);
    return 0;
}