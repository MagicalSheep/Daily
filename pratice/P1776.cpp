#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, W, f[MAXN], g[MAXN], q[MAXN], head, tail;

int main()
{
    scanf("%d%d", &n, &W);
    for (int i = 1; i <= n; i++)
    {
        int v, w, m;
        scanf("%d%d%d", &w, &v, &m);
        for (int j = 0; j < v; j++)
        {
            head = 0, tail = -1;
            for (int k = 0; j + k * v <= W; k++)
            {
                while (head <= tail && k - q[head] > m)
                    ++head;
                if (head <= tail)
                    f[j + k * v] = max(f[j + k * v], g[j + q[head] * v] + (k - q[head]) * w);
                while (head <= tail && (g[j + q[tail] * v] - q[tail] * w) < (g[j + k * v] - k * w))
                    --tail;
                q[++tail] = k;
            }
        }
        for (int j = 0; j <= W; j++)
            g[j] = f[j];
    }
    printf("%d\n", f[W]);
    return 0;
}