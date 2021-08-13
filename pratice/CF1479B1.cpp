#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, f[MAXN], a[MAXN];
set<int> s;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    int inc = 0;
    priority_queue<pair<int, int>> q;
    for (int x : s)
        q.push(pair<int, int>(f[x], x));
    for (int i = 1; i <= n; i++)
    {
        int mx = 0;
        bool flag = false;
        while (q.size())
        {
            pair<int, int> t = q.top();
            if (t.second == a[i])
            {
                flag = true;
                q.pop();
            }
            else
            {
                mx = t.first;
                break;
            }
        }
        if (flag)
            q.push(pair<int, int>(f[a[i]], a[i]));
        inc += (a[i] != a[i - 1]);
        f[a[i - 1]] = mx + 1 - (a[i] != a[i - 1]); // I don't know why it is correct, but it works well.
        q.push(pair<int, int>(f[a[i - 1]], a[i - 1]));
    }
    int ans = 0;
    for (int x : s)
        ans = max(ans, f[x] + inc);
    printf("%d\n", ans);
    return 0;
}