#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if ((2 * b - c) % a == 0)
        {
            int m = (2 * b - c) / a;
            if (m > 0 && b - m * a == c - b)
            {
                printf("YES\n");
                continue;
            }
        }
        if ((a + c) % (2 * b) == 0)
        {
            int m = (a + c) / (2 * b);
            if (m > 0 && m * b - a == c - m * b)
            {
                printf("YES\n");
                continue;
            }
        }
        if ((2 * b - a) % c == 0)
        {
            int m = (2 * b - a) / c;
            if (m > 0 && b - a == m * c - b)
            {
                printf("YES\n");
                continue;
            }
        }
        printf("NO\n");
    }
    return 0;
}