#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t, n, a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        printf("%d\n", a[n] - a[1]);
    }
    return 0;
}