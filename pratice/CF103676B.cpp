#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int n, ans;
pair<int, int> a[MAXN];
vector<int> g[MAXN];

bool solve()
{
    for (int ptr = 1; a[n].first; ptr++)
    {
        sort(a + 1, a + 1 + n);
        int st = n - a[ptr].first + 1;
        if (st <= ptr)
            return false;
        for (int i = st; i <= n; i++)
        {
            g[a[ptr].second].emplace_back(a[i].second);
            ++ans;
            --a[i].first;
        }
        a[ptr].first = 0;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].first), a[i].second = i;
    if (!solve())
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++)
            for (auto v : g[i])
                printf("%d %d\n", i, v);
    }
    return 0;
}