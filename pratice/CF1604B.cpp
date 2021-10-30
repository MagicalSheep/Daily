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
        if (n % 2 == 0)
        {
            printf("YES\n");
            continue;
        }
        bool isok = false;
        for (int i = 1; i < n; i++)
        {
            if (a[i] >= a[i + 1])
            {
                isok = true;
                break;
            }
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}