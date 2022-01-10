#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int t, n;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s + 1);
        vector<int> ans, ans2;
        int rb = n + 1;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == '0')
                continue;
            while (s[--rb] != '0')
            {
            }
            if (rb < i)
                break;
            ans.emplace_back(i);
            ans2.emplace_back(rb);
        }
        if (ans.size() == 0)
        {
            printf("%d\n", 0);
        }
        else
        {
            printf("1\n%d ", ans.size() + ans2.size());
            reverse(ans2.begin(), ans2.end());
            for (auto x : ans)
                printf("%d ", x);
            for (auto x : ans2)
                printf("%d ", x);
            printf("\n");
        }
    }
    return 0;
}