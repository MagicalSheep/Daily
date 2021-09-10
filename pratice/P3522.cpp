#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, x[MAXN], y[MAXN], be, ans;
deque<int> q;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    ans = be = 1;
    q.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        while (q.size() && x[q.front()] > y[i])
            be = q.front() + 1, q.pop_front();
        ans = max(ans, i - be + 1);
        while (q.size() && x[q.back()] < x[i])
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n", ans);
    return 0;
}