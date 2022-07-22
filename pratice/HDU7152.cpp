#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int t, n, q, a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int ans = 0;
        while (q--)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int l, r;
                scanf("%d%d", &l, &r);
                if (r == n)
                    continue;
                for (int i = r + 1; i <= n; i++)
                    b[i] = a[i];
                for (int i = r + 1, j = r + r - l + 2; i <= n && j <= n; i++, j++)
                    a[j] = b[i];
                for (int i = l, j = r + 1; i <= r && j <= n; i++, j++)
                    a[j] = a[i];
            }
            else
            {
                int x;
                scanf("%d", &x);
                ans ^= a[x];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}