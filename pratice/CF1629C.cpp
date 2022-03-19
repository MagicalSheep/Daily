#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, a[MAXN], cnt[MAXN];

void solve()
{
    vector<int> ans;
    unordered_map<int, int> vis;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        vis[a[i]] = 1;
        if (a[i] == cur)
            while (vis[cur])
                ++cur;
        --cnt[a[i]];
        if (!cnt[cur])
        {
            ans.emplace_back(cur);
            vis.clear();
            cur = 0;
        }
    }

    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), cnt[a[i]]++;
        solve();
    }
    return 0;
}