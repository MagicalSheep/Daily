#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n, m;

int dis(int x, int y)
{
    int ret = abs(x - 1) + abs(y - 1);
    ret = max(ret, abs(x - 1) + abs(y - m));
    ret = max(ret, abs(x - n) + abs(y - 1));
    ret = max(ret, abs(x - n) + abs(y - m));
    return ret;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans.emplace_back(dis(i, j));
        sort(ans.begin(), ans.end());
        for (auto x : ans)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}