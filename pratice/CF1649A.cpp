#include <bits/stdc++.h>
using namespace std;

int t, n, a[100 + 5];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int l = 1, r = n;
        while (a[l] == 1)
            ++l;
        while (a[r] == 1)
            --r;
        --l, ++r;
        printf("%d\n", max(0, r - l));
    }
    return 0;
}