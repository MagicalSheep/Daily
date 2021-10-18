#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;

int t, n, k, ind[MAXN], cen[MAXN];
vector<int> edge[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].emplace_back(v);
            edge[v].emplace_back(u);
            ind[u]++, ind[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (ind[i] == 1)
                q.push(i), cen[i] = 1;
        while (q.size())
        {
            int u = q.front();
            q.pop();
            --ind[u];
            for (auto v : edge[u])
            {
                --ind[v];
                if (ind[v] == 1)
                    q.push(v), cen[v] = cen[u] + 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (cen[i] > k)
                ans++;
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            cen[i] = 0, ind[i] = 0, edge[i].clear();
    }
    return 0;
}