#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool isok = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] & 1)
                continue;
            if (a[i] <= i)
                continue;
            bool flag = false;
            for (int j = i; j >= 1; j--)
            {
                if ((a[i] % (j + 1)) != 0)
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                isok = false;
                break;
            }
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}