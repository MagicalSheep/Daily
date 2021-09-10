#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, d[MAXN], q, k, f[MAXN], Q[MAXN], head, tail;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &k);
        head = 0, tail = -1;
        Q[++tail] = 1;
        for (int i = 2; i <= n; i++)
        {
            while (head <= tail && Q[head] < max(1, i - k))
                ++head;
            f[i] = (d[Q[head]] > d[i]) ? f[Q[head]] : f[Q[head]] + 1;
            while (head <= tail && (f[Q[tail]] > f[i] || (f[Q[tail]] == f[i] && d[Q[tail]] < d[i])))
                --tail;
            Q[++tail] = i;
        }
        printf("%d\n", f[n]);
    }
    return 0;
}