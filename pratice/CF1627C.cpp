#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n, cnt[MAXN];
vector<pair<int, int>> edge[MAXN], ans;

void dfs(int u, int fa, int color)
{
    for (auto v : edge[u])
    {
        if (v.first != fa)
        {
            ans.push_back({v.second, color});
            dfs(v.first, u, (color == 2) ? 3 : 2);
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].emplace_back(pair<int, int>(v, i));
            edge[v].emplace_back(pair<int, int>(u, i));
            ++cnt[u];
            ++cnt[v];
        }
        int c1 = 0, c2 = 0, st;
        for (int i = 1; i <= n; ++i)
        {
            if (cnt[i] == 1)
                ++c1, st = i;
            if (cnt[i] == 2)
                ++c2;
        }
        if (c1 + c2 < n)
        {
            printf("-1\n");
            for (int i = 1; i <= n; i++)
                cnt[i] = 0, edge[i].clear();
            continue;
        }
        dfs(st, -1, 2);
        sort(ans.begin(), ans.end());
        for (auto x : ans)
            printf("%d ", x.second);
        printf("\n");
        ans.clear();
        for (int i = 1; i <= n; i++)
            cnt[i] = 0, edge[i].clear();
    }
    return 0;
}