#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
#define INF 0x3f3f3f3f

int t, n, k, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[n + 1] = INF;
        priority_queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n + 1; i++)
        {
            if (k > 0)
            {
                int j = i;
                while (j >= 1 && a[j] < a[i + 1])
                {
                    if (a[j] > 0)
                    {
                        if (j < i)
                            ans.pop_back();
                        q.push(a[j]);
                        a[j] = 0;
                        --k;
                    }
                    --j;
                }
                if (j == i)
                    ans.emplace_back(a[i]);
            }
            else
            {
                while (!q.empty() && q.top() > a[i])
                {
                    ans.emplace_back(q.top());
                    q.pop();
                }
                ans.emplace_back(a[i]);
            }
        }
        while (!q.empty())
        {
            ans.emplace_back(q.top());
            q.pop();
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == INF)
                continue;
            if (i != ans.size() - 1)
                printf("%d ", ans[i]);
            else
                printf("%d\n", ans[i]);
        }
    }
    return 0;
}