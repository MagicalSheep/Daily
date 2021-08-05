#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int T, n, m, b[MAXN];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d", &b[i]);
        if (n == m)
        {
            printf("YES\n");
            continue;
        }
        int l, r, left = 0, right = 0;
        bool isok = false;
        sort(b + 1, b + 1 + m);
        b[m + 1] = b[m];
        for (int i = 1; i <= m; i++)
        {
            l = b[i] - i - left;
            r = n - b[i] - (m - i) - right;
            int delta = b[i + 1] - b[i] - 1;
            if (l == r || l + 1 == r)
            {
                isok = true;
                break;
            }
            if (l > r)
            {
                isok = false;
                break;
            }
            if (l == 0)
            {
                if (r == 1)
                {
                    isok = true;
                    break;
                }
                left = n - r - m;
                right = 0;
                continue;
            }
            if (l + 1 <= delta)
            {
                left = 2 * l + 1;
                right = 0;
            }
            else
            {
                left = l + delta;
                right = l - delta + 1;
            }
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}