#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, rt, dep[MAXN];
vector<int> g[MAXN];
vector<vector<int>> paths;

void dfs1(int u)
{
    for (auto v : g[u])
    {
        dep[v] = dep[u] + 1;
        dfs1(v);
    }
}

void dfs2(int u, vector<int> &vec)
{
    vec.emplace_back(u);
    if (g[u].empty())
    {
        paths.emplace_back(vec);
        return;
    }
    int mx = 0;
    for (auto v : g[u])
        if (dep[v] > dep[mx])
            mx = v;
    for (auto v : g[u])
    {
        if (v != mx)
        {
            vector<int> ve;
            dfs2(v, ve);
        }
        else
        {
            dfs2(v, vec);
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int in;
            scanf("%d", &in);
            if (in == i)
                rt = i;
            else
                g[in].emplace_back(i);
        }
        dep[rt] = 1;
        dfs1(rt);
        vector<int> vec;
        dfs2(rt, vec);
        printf("%d\n", paths.size());
        for (auto path : paths)
        {
            printf("%d\n", path.size());
            for (auto x : path)
                printf("%d ", x);
            printf("\n");
        }
        if (t)
            printf("\n");

        for (int i = 1; i <= n; i++)
            g[i].clear(), dep[i] = 0;
        paths.clear();
    }
    return 0;
}