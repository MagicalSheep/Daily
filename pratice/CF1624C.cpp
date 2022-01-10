#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n, a[MAXN];
vector<vector<int>> d(MAXN);
vector<bool> vis(MAXN);

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            while (a[i] > n)
                a[i] /= 2;
            mx = max(mx, a[i]);
        }
        if (mx < n)
        {
            printf("NO\n");
            continue;
        }
        for (int i = 0; i < d.size(); i++)
            d[i].clear();
        for (int i = 0; i < vis.size(); i++)
            vis[i] = false;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            while (a[i] > 1)
            {
                d[a[i]].emplace_back(i);
                a[i] /= 2;
            }
            d[a[i]].emplace_back(i);
        }
        bool isok = true;
        for (int i = n; i >= 1; i--)
        {
            bool found = false;
            for (int j = n; j >= 1; j--)
            {
                if (vis[j])
                    continue;
                if (find(d[i].begin(), d[i].end(), j) != d[i].end())
                {
                    vis[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                isok = false;
                break;
            }
        }
        if (isok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}