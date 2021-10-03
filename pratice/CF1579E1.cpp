#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        deque<int> q;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int in = 0;
            scanf("%d", &in);
            if (q.empty() || q.front() > in)
                q.emplace_front(in);
            else
                q.emplace_back(in);
        }
        for (auto x : q)
            printf("%d ", x);
        printf("\n");
    }
    return 0;
}