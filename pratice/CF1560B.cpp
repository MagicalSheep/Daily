#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int n = abs(a - b) * 2;
        int d;
        if (c > (n / 2))
            d = c - (n / 2);
        else
            d = (n / 2) + c;
        if (a <= n && b <= n && c <= n && d <= n)
            printf("%d\n", d);
        else
            printf("-1\n");
    }
    return 0;
}