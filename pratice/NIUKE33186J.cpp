#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, fa[MAXN], siz[MAXN];
set<int> from[MAXN], to[MAXN];

int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}

void merge(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x == y)
        return;
    if (siz[x] < siz[y])
        swap(x, y);
    fa[y] = x;
    siz[x] += siz[y];
    vector<int> vec;
    for (auto v : to[y])
    {
        to[x].insert(v);
        from[v].insert(x);
        from[v].erase(y);
        if (from[v].size() == 1)
            vec.emplace_back(v);
    }
    for (auto v : vec)
        merge(x, v);
}

int main()
{
    scanf("%d", &t);
    for (int c = 1; c <= t; c++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int cnt, x;
            scanf("%d", &cnt);
            for (int j = 1; j <= cnt; j++)
            {
                scanf("%d", &x);
                from[i].insert(x);
                to[x].insert(i);
            }
        }
        for (int i = 1; i <= n; i++)
            fa[i] = i, siz[i] = 1;
        for (int i = 1; i <= n; i++)
            if (from[i].size() == 1)
                merge(*(from[i].begin()), i);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, siz[i]);
        printf("Case #%d: %d\n", c, ans);
        for (int i = 1; i <= n; i++)
            from[i].clear(), to[i].clear();
    }
    return 0;
}