#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, a[MAXN] = {0};
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[n + 1] = 1;
        if (a[n] == 0)
        {
            for (int i = 1; i <= n + 1; i++)
                printf("%d ", i);
            printf("\n");
            continue;
        }
        if (a[1] == 1)
        {
            printf("%d ", n + 1);
            for (int i = 1; i <= n; i++)
                printf("%d ", i);
            printf("\n");
            continue;
        }
        int x, isok = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0 && a[i + 1] == 1)
            {
                isok = 1, x = i;
                break;
            }
        }
        if (isok == 0)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= x; i++)
            printf("%d ", i);
        printf("%d ", n + 1);
        for (int i = x + 1; i <= n; i++)
            printf("%d ", i);
        printf("\n");
    }
    return 0;
}