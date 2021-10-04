#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int t, n, d, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        scanf("%d%d", &n, &d);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == 0)
                q.push(pair<int, int>(0, i));
        }
        int cnt = 0;
        while (q.size())
        {
            pair<int, int> x = q.top();
            q.pop();
            x.second = (x.second + d) % n;
            if (a[x.second] == 0)
                continue;
            a[x.second] = 0;
            x.first++;
            cnt = max(cnt, x.first);
            q.push(x);
        }
        bool isok = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i])
            {
                isok = false;
                break;
            }
        }
        if (isok)
            printf("%d\n", cnt);
        else
            printf("-1\n");
    }
    return 0;
}