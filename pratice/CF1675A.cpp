#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, x, y;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
        x -= a;
        y -= b;
        x = max(0, x);
        y = max(0, y);
        if (c >= x + y)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}