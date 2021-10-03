#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n, b[MAXN], vis[MAXN], sum[MAXN];

struct obj
{
    int idx, times;
} a[MAXN];

struct cmp
{
    bool operator()(obj x, obj y) { return x.times <= y.times; }
};

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vector<pair<int, int>> ans;
        priority_queue<obj, vector<obj>, cmp> q;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].times), a[i].idx = i, q.push(a[i]);

        while (q.size())
        {
            obj x = q.top();
            q.pop();
            if (q.empty())
                break;
            obj y = q.top();
            q.pop();
            if (x.times && y.times)
            {
                x.times--, y.times--;
                ans.emplace_back(pair<int, int>(x.idx, y.idx));
                q.push(x), q.push(y);
            }
            else
            {
                if (x.times)
                    q.push(x);
                if (y.times)
                    q.push(y);
            }
        }

        printf("%d\n", ans.size());
        for (auto x : ans)
            printf("%d %d\n", x.first, x.second);
    }
    return 0;
}