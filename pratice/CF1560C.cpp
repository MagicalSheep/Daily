#include <bits/stdc++.h>
using namespace std;

int t, k;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &k);
        int n = ceil(sqrt((double)k));
        int d = n * (n - 1) + 1;
        int i, j;
        if (k < d)
            j = n, i = n - d + k;
        else if (k == d)
            i = n, j = n;
        else
            i = n, j = n - k + d;
        printf("%d %d\n", i, j);
    }
    return 0;
}