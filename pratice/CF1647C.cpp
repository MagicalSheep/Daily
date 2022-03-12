#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int t, n, m;
char a[MAXN][MAXN];

void solve()
{
    if (a[1][1] == '1')
    {
        printf("-1\n");
        return;
    }
    vector<pair<int, int>> ans1, ans2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 2; j--)
        {
            if (a[i][j] == '1')
            {
                ans1.emplace_back(pair<int, int>(i, j - 1));
                ans2.emplace_back(pair<int, int>(i, j));
            }
        }
    }
    for (int i = n; i >= 2; i--)
    {
        if (a[i][1] == '1')
        {
            ans1.emplace_back(pair<int, int>(i - 1, 1));
            ans2.emplace_back(pair<int, int>(i, 1));
        }
    }
    printf("%d\n", ans1.size());
    for (int i = 0; i < ans1.size(); i++)
        printf("%d %d %d %d\n", ans1[i].first, ans1[i].second, ans2[i].first, ans2[i].second);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        solve();
    }
    return 0;
}