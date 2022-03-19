#include <bits/stdc++.h>
using namespace std;

int t, l, r, k;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &l, &r, &k);
        if (l == r)
        {
            if (l == 1)
                printf("NO\n");
            else
                printf("YES\n");
            continue;
        }
        int cnt = (r - l + 1) - (r / 2 - (l - 1) / 2);
        if (k >= cnt)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}